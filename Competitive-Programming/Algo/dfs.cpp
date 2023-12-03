// DFS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<bool> visited;   // Visited array

void dfs(int v) {
    // Put code here if you want to do something after arrving a node

    visited[v] = true;  // Set current node as visited

    // Here is the loop for checking for neighbours
    for (int u : adj[v]) {  // Loop through all the neighbour, iterate to next one only if all depth has proceeded

        // Here to handle the conditions to visit a neighbour
        if (!visited[u])    // If the neighbor is not visited (otherwise infinite loop)
            dfs(u); // Call dfs on the neighbours
    }

    // Put code here after all the neighbours are visited and return back to the node


}

int main(){
    for (int i = 0; i < n; i++){
        int u, v; cin >> u >> v;
        // Undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = 1;
    dfs(start);
}

/*
 * Note:
 * - Not the shortest path
 * - “Simpler” as no queue
 * Application:
 * Check for connectivity btw two nodes
 * Check if the graph has cycle
 */




