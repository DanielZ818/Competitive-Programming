// Dijkstra with priority queue
// Time complexity: O(m * log_n)
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int dest;
    int cost;
    Edge(int dest, int cost): dest(dest), cost(cost) {}
};

struct Node {
    int node;
    int cost;
    Node(int node, int cost): node(node), cost(cost) {}
    bool operator<(const Node& other) const {
        return cost > other.cost; // Sort based on cost from min to max
    }
};

const int INF = 1e9;
vector<vector<Edge>> adj;
vector<int> dis; // distance from starting node
vector<int> parent;


void dijkstra (int start) {
    dis.assign(dis.size(), INF); // Initialize all to max
    parent.assign(parent.size(), -1); // No parents
    set<Node> priority_queue;

    // Add start node
    Node start_node = Node(start, 0);
    dis[start] = start_node.cost;
    priority_queue.insert(start_node);

    // until queue is empty
    while (!priority_queue.empty()) {
        // Get and remove the first node (which has the smallest cost)
        Node cur = *priority_queue.begin();
        priority_queue.erase(priority_queue.begin());

        // on the smallest node
        int cur_node = cur.node, cur_cost = cur.cost;

        // Visit all its neighbours
        for (auto neighbour: adj[cur_node]) {
            // neighbours has node at `neighbour_node` and path with a cost of `cur_to_neighbour_cost`
            int neighbour_node = neighbour.dest, cur_to_neighbour_cost = neighbour.cost;

            // We can also get neighbour node's current cost of 'neighbour_original_cost' from distance array
            int neighbour_original_cost = dis[neighbour_node];

            // Calculate the new cost by adding current cost and path cost
            int new_neighbour_cost = cur_cost + cur_to_neighbour_cost;


            // If it is more efficient to go from current node to neighbour, then perform 'relaxation'
            if (new_neighbour_cost < neighbour_original_cost) {
                // Remove the original neighbour node
                priority_queue.erase(Node(neighbour_node, dis[neighbour_node])); // erase original neighbour with original cost

                // Update the distance to new cost
                dis[neighbour_node] = new_neighbour_cost;

                // Set the neighbour node's parent to current node
                parent[neighbour_node] = cur_node;

                // Add neighbour's node into the queue
                priority_queue.insert(Node(neighbour_node, new_neighbour_cost)); // new neighbour node with new cost
            }
        }
    }
}

vector<int> restore_path(int start, int end) {
    vector<int> path;
    // continue restore until it reaches start node
    for (int v = end; v != start; v = parent[v])
        path.push_back(v);
    path.push_back(start); // add the start node as well
    reverse(path.begin(), path.end()); // reverse the path from it goes like start -> last
    return path;
}

void solve() {
    // 1-indexed
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

    for (int i = 1; i <= n; i++) {
        cout << "From " << i << " can reach: ";
        for (auto j: adj[i]) {
            cout << j.dest << "(" << j.cost << "), ";
        }
        cout << endl;
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
10 12
1 2 4
5 7 1
4 6 4
7 9 3
9 10 1
7 8 5
1 3 1
6 7 4
4 5 1
3 4 2
8 10 5
2 4 3
*/

/*
The minimum step from:
Vertex 1 to vertex 1 is: 0      Path: 1
Vertex 1 to vertex 2 is: 4      Path: 1 2
Vertex 1 to vertex 3 is: 1      Path: 1 3
Vertex 1 to vertex 4 is: 3      Path: 1 3 4
Vertex 1 to vertex 5 is: 4      Path: 1 3 4 5
Vertex 1 to vertex 6 is: 7      Path: 1 3 4 6
Vertex 1 to vertex 7 is: 11     Path: 1 3 4 6 7
Vertex 1 to vertex 8 is: 16     Path: 1 3 4 6 7 8
Vertex 1 to vertex 9 is: 14     Path: 1 3 4 6 7 9
Vertex 1 to vertex 10 is: 15    Path: 1 3 4 6 7 9 10
*/


int main () {
    solve();
}





