// Tree
#include<bits/stdc++.h>
using namespace std;


// Traverse tree with DFS
// Tree is a special type of graph, just like all other graph with a few properties
// - Without Cycles
// - N node, N-1 edge
// - At most one path from one node to another, as for no cycles
// - Therefore, the one and the only path is the best path, can be discovered by dfs
// - Can be bidirectional

const int MAX = 100;
vector<int> adj[MAX]; // adjacency array track of neighbours

void dfs(int v, int p){
    cout << "Visiting: " << v << endl;
    for(int u : adj[v]){  // Iterate through neighbours
        if (u == p) continue;  // if neighbour node is parent, skip
        dfs(u, v);  // proceed to next level depth
    }
}

int main(){
    // Constructing a tree
    int n; cin >> n; // n nodes
    int e; cin >> e; // e edges
    for (int i = 0; i < e; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 2; i <= n; i++){ // Node
        int p; cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dfs(1, -1);
}
