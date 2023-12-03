// Cycle Detection - Problem Implementation
// CSEC Round Trip
#include <bits/stdc++.h>

using namespace std;


const int MAX_N = 10e5 + 5;
const int MAX_M = 2 * 10e5 + 5;

vector<int> adj[MAX_N];
int visited[MAX_M];
vector<int> parent(MAX_N);

void dfs(int v){
    visited[v] = 2;
    for(int u : adj[v]){
        // Neighbour is parent
        if (u == parent[v]) {
            continue;
        }

        // Neighbour has been visited
        if (visited[u] == 1){
            continue;
        }

        // Back to parent
        if (visited[u] == 2){ // detected cycle
            // Retrace cycle path
            vector<int> pp;
            int cur = v;
            while (cur != u) { // Trace back until it finds current
                pp.push_back(cur);
                cur = parent[cur];
            }
            pp.push_back(cur);
            pp.push_back(v);
            cout << pp.size() << endl;
            for (int i: pp)
                cout << i << " ";
            cout << endl;
            exit(0);
        }

        // Visiting next neighbour
        parent[u] = v; // next node has parent of this node
        dfs(u);
    }
    visited[v] = 1;
}

int main(){
    int N; // N nodes (cities)
    int M; // M edges (roads)
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for(int i = 1; i <= N; i++) {
        if (!visited[i]) dfs(i);
    }
    cout << "IMPOSSIBLE" << endl;

}