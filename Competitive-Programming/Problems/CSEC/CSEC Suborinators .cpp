// Tree
// CSEC Subordinates
#include <bits/stdc++.h>
using namespace std;


// For this problem, we are looking for how many subtrees were included in a node
// Approach: We know that tree has no cycles: meaning one node will be only visited once
// Then, when ever each neighbour is terminated or returning back to its parent, the parent is its child node += 1
// And for the edge nodes, the last one who has no trees under (no neighbour) it will be 0 += 1 as its the last layer
// Basically finding the last layer and count up

const int MAX = 2000001;
vector<int> adj[2000001];
int sz[MAX];

void dfs(int v, int p){
    for(int u : adj[v]){
        if(u == p)continue;
        dfs(u, v);
        sz[v] += sz[u]; // after child has been terminated, the layer add itself
    }
    sz[v] += 1; // to include self as subtree or not
}
int main(){
    int n; cin >> n;
    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dfs(1, -1);
    for(int i = 1; i <= n; i++){
        cout << sz[i] - 1 << ' ';
    }
    cout << '\n';
}


