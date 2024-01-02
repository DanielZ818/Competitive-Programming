#include <bits/stdc++.h>
using namespace std;


const int INF = 1e9;
vector<vector<pair<int, int>>> adj;
vector<int> dis;  // Stored the minimum distance
vector<int> parent;  // For retrace the route

void dijkstra(int start) {
    int n = adj.size();
    dis.assign(n, INF); // Set to inf
    parent.assign(n, -1);
    vector<bool> marked(n, false);

    dis[start] = 0;
    for (int i = 1; i <= n; i++) {
        int v = -1;  // Minimum distance vertex to the source
        // Finding the minimum distance vertex to the source
        for (int j = 1; j <= n; j++)
            if (!marked[j] and (v == -1 or dis[j] < dis[v]))  // -1 is the start
                v = j;

        if (dis[v] == INF) break;

        marked[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                parent[to] = v;
            }
        }
    }
}

vector<int> restore_path(int start, int end) {
    vector<int> path;

    for (int v = end; v != start; v = parent[v])
        path.push_back(v);
    path.push_back(start);

    reverse(path.begin(), path.end());
    return path;
}

void solve(){
    int n, m; // n vertices, m edges
    cin >> n >> m;
    adj.resize(n + 1);
    dis.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v, w;  // vertex1, vertex2, weight
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // single direction
        adj[v].push_back({u, w}); // or bi-directional
    }

    int start_vertex = 1;
    dijkstra(start_vertex);
    cout << "The minimum step from:" << endl;
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) {
            cout << "Vertex " << start_vertex << " to vertex " << i << " is: " << "Unreachable" << endl;
            continue;
        }
        cout << "Vertex " << start_vertex << " to vertex " << i << " is: " << dis[i];
        cout << "\tPath: ";
        for (auto j: restore_path(start_vertex, i)) cout << j << " ";
        cout << endl;
    }
}

/*
Sample input:
4 3
1 2 2
1 3 5
2 3 2
*/

/*
Sample output:
The minimum step from:
Vertex 1 to vertex 1 is: 0      Path: 1
Vertex 1 to vertex 2 is: 2      Path: 1 2
Vertex 1 to vertex 3 is: 4      Path: 1 2 3
Vertex 1 to vertex 4 is: Unreachable
*/

/*
4 4
1 2 24
1 4 20
3 1 3
4 3 12
*/

/*
The minimum step from:
Vertex 1 to vertex 1 is: 0      Path: 1
Vertex 1 to vertex 2 is: 24     Path: 1 2
Vertex 1 to vertex 3 is: 3      Path: 1 3
Vertex 1 to vertex 4 is: 15     Path: 1 3 4
*/

int main(){
    solve();
}