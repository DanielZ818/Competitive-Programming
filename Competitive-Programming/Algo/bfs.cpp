/*
Bfs:
- Check if two nodes are connected
- Find minimum number for edge (distance) from node A to B
- No need to compare if distance A to B is bigger than A to C to B as assume weight always equal
- Don’t visited a node twice
- Loop infinitely if not having a visited array
https://cp-algorithms.com/graph/breadth-first-search.html
 */

#include <bits/stdc++.h>
using namespace std;

void retrace(int u, vector<bool> visited, vector<int> parent);

int main(){
    vector<vector<int>> adj;  // adjacency list representation - adj[A] = {B, C, D} - node A have neighbors of B, C, D
    int n = 5; // number of nodes
    int start = 1; // Starting node
    int end = 4; // Ending node

    queue<int> queue;   // Queue for where to visit next
    vector<bool> visited(n);   // Visited array
    vector<int> distance(n); // Step for calculating min steps from start to wherever
    vector<int> parent(n); // Parent array keep track of retrace the path

    queue.push(start);  // Add the starting node
    visited[start] = true; // Set starting node as visited
    parent[start] = -1; // Starting node does not have a parent
    while (!queue.empty()) {    // When there are unvisited neighbors
        int v = queue.front();  // Get the first neighbor
        queue.pop();            // Remove from queue
        for (int u : adj[v]) {  // Find all neighbors connected to current node
            // U = current neighbor, V = current node (or its parent)
            if (!visited[u]) { // If the neighbor has not been visited
                visited[u] = true; // Visited = true
                queue.push(u); // Add to queue
                distance[u] = distance[v] + 1; // Current neighbor step = its parent + 1
                parent[u] = v;   // Set this neighbor's parent as current node
            }
        }
    }

    cout << "The distance (min) from " << start << " to " << end << " is " << distance[end] << endl;
    retrace(end, visited, parent);

}

// Retrace path from start node to end node
void retrace(int u, vector<bool> visited, vector<int> p){
    // u = the node you want to check
    if (!visited[u]) { // Check if the node is ever visited, used[u] == false means it is never visited -> not connected
        cout << "No path!";
    }

    else {  // If there is a path from start to end
        vector<int> path; // Vector to store the path how start node visit end node
        for (int v = u; v != -1; v = p[v]) // Starting from end node, trace back by changing to parent, stop when found the first node which has root 1
            path.push_back(v);  // Add parent of the node to the path array
        reverse(path.begin(), path.end()); // Reverse the path so it goes from start -> end and not other way around

        cout << "Path: ";
        for (int v : path)  // Print out the path
            cout << v << " ";
        cout << endl;
    }
}
