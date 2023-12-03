// Water filling problem
// Relational neighbours (no grid, adj list)
// Transit from one node another by custom relationship

/*
Problem:
Given two cups A and B.
A can hold k litres, and B and hold t litres.
Starting with two cups empty.
Each step can either fill one of the cup to full,
Or Pour water from A to B, or B to A (and not exceed the other cups limit),
Or empty one of the cup.
Determine if is possible and the minimum steps required (at most 30 steps) to fill one of the cup to target (x)

Example:
    Given k = 7, t = 5, x = 4 (target)
    (m, n) denotes A has volume of m and B has volume of n
    Start at two cups empty (0, 0)
    Step 1: Fill A full (7, 0)
    Step 2: Pour water from A to B (2, 5)
    Step 3: Empty B (2, 0)
    Step 4: Pour water from A to B (0, 2)
    Step 5: Fill A to full (7, 2)
    Step 6: Pour water from A to B (4, 5)
            Target Reached!
    Therefore, the step is 6.
    But is this the minimum?
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int, int> PII;
typedef vector<int> VI;


void retrace(PII u, vector<vector<bool>> visited, vector<vector<PII>> parent);

void solve() {
    int n = 30; // Nodes to max step

    int k = 7; // A's volume
    int t = 5; // B's volume
    int target = 4; // Target (x)

    // (x, y) represent volume in cup A(x) and B(y)
    PII start = {0, 0};
    // end = {Any, target} or {target, Any}


    queue<PII> queue;   // Queue for where to visit next
    vector<vector<bool>> visited;   // Visited array
    visited.resize(n+1, vector<bool>(n+1));
    vector<vector<int>> distance; // Step for calculating min steps from start to wherever
    distance.resize(n+1, vector<int>(n+1));
    vector<vector<pair<int, int>>> parent;
    parent.resize(n+1, vector<PII>(n+1));

    queue.push(start);  // Add the starting node
    parent[start.first][start.second] = {-1, -1};
    visited[start.first][start.second] = true; // Set starting node as visited

    while (!queue.empty()) {    // When there are unvisited neighbors
        PII cur = queue.front();  // Get the first neighbor
        queue.pop();            // Remove from queue

        int x = cur.first, y = cur.second;

        if (x == target or y == target) {
            cout << "Path found! Steps: " << distance[x][y] << endl;
            retrace(cur, visited, parent);
            return;
        }

        // Three kind of neighbours
        // 1. fill to full (k, y) or (x, t)
        if (!visited[k][y]) {
            visited[k][y] = true;
            queue.emplace(k, y);
            distance[k][y] = distance[x][y] + 1;
            parent[k][y] = cur;
        }
        if (!visited[x][t]) {
            visited[x][t] = true;
            queue.emplace(x, t);
            distance[x][t] = distance[x][y] + 1;
            parent[x][t] = cur;
        }

        // 2. empty one
        if (!visited[0][y]) {
            visited[0][y] = true;
            queue.emplace(0, y);
            distance[0][y] = distance[x][y] + 1;
            parent[0][y] = cur;
        }
        if (!visited[x][0]) {
            visited[x][0] = true;
            queue.emplace(x, 0);
            distance[x][0] = distance[x][y] + 1;
            parent[x][0] = cur;
        }

        // 3. pour one to another
        // A to B (x, y) -> (x-poured , y + poured) max
        int max_possible = t - y;
        int poured = min(max_possible, x);
        // (x,y) -> (x-poured, y+poured);
        if (!visited[x-poured][y+poured]) {
            visited[x-poured][y+poured] = true;
            queue.emplace(x-poured, y+poured);
            distance[x-poured][y+poured] = distance[x][y] + 1;
            parent[x-poured][y+poured] = cur;
        }

        // B to A (x,y) -> (x+poured, y-poured)
        max_possible = k - x;
        poured = min(max_possible, y);
        if (!visited[x+poured][y-poured]) {
            visited[x+poured][y-poured] = true;
            queue.emplace(x+poured, y-poured);
            distance[x+poured][y-poured] = distance[x][y] + 1;
            parent[x+poured][y-poured] = cur;
        }
    }
    cout << "No possible path!" << endl;
}



void retrace(PII u, vector<vector<bool>> visited, vector<vector<PII>> parent){
    int x = u.first, y = u.second;

    vector<PII> path; // Vector to store the path how start node visit end node
    for (PII cur = u; cur.first !=-1 and cur.second != -1; cur = parent[cur.first][cur.second])
        path.push_back(cur);

    reverse(path.begin(), path.end()); // Reverse the path so it goes from start -> end and not other way around

    cout << "Path: ";
    for (PII v : path)  // Print out the path
        cout << "(" << v.first << "," << v.second << ") ";
    cout << endl;

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
