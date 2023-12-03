// Cycle Detection
#include<bits/stdc++.h>
using namespace std;

// This can be used in any graph

vector<int> adj[100]; // adjacency array track of neighbours
int visited[100];   // Visited array to know if it is the second time visiting node
// visited[u] == 0: the node has never reached, not as neighbour nor parent
// visited[u] == 1: the node has been reached
// visited[u] == 2: the node has been reached as parent. We are on this node right now.
// If we visit visited[u] == 2 again, meaning we return back to the same node. There is a cycle formed within the graph


void dfs(int v, int par){
    visited[v] = 2; // On this node right now
    for(int u : adj[v]){    // basic dfs: loop through neighbours
        if (u == par) continue;  // skip if neighbour == parent
        if (visited[u] == 2){   // If the current node is the one we start with
            cout << "CYCLE FOUND!\n";
            exit(0);    // Terminate
        }
        if (visited[u] == 1){   // skip if already visited as neighbour or (already visited like bfs)
            continue;
        }
        dfs(u, v); // dfs on this neighbour
    }
    visited[v] = 1; // Reset current node as visited
}

int main(){
    int N; // N nodes
    int M; // M edges
    cin >> N >> M;

    // Construct graph
    for(int i = 0; i < M; i++){
        int u, v; // Two nodes connected
        cin >> u >> v;
        adj[u].push_back(v); // Bidirectional
        adj[v].push_back(u);
    }

    // Check cycle starting from every node
    // Because some node can be in different set of graph that is not connected
    for(int i = 1; i <= N; i++){
        if (!visited[i]) dfs(i, -1);
    }

}