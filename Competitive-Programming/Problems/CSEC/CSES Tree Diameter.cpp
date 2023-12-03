// The diameter of a tree
// https://cses.fi/problemset/task/1131/

#include <bits/stdc++.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(var, start, end, incr) for (int var=start ; var<end ; var+=incr)
#define RFOR(var, start, end, decr) for (int var=start ; var>=k ; var-=decr)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(var, where) for (auto var = where.begin(); var != where.end(); var++)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n'
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef unordered_map<int,int> UMPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

// Comment this out to not use DEBUG_MODE
//#define DEBUG_MODE
#ifdef DEBUG_MODE
    ifstream DEBUG_IN("input.txt");
    #define cin DEBUG_IN
#endif


// Quite interesting algorithm
// To find the diameter of a tree (the longest distance from one node to another)
// First dfs from any random node to another (DFS will eventually stop)
// Find the node that has the longest distance from that starting node
// Do DFS again
// The longest node for this starting node will be the diameter

// and this is how you should calculate the distance from starting node to ending node by accessing step[starting_node]

// MAKE SURE you decide should the graph starting at 1 (usually input data) or 0 (how index works)

const int MAX = 2 * 10e5 + 5;
vector<int> adj[MAX]; // adjacency array track of neighbours
int * step; // Step array

void dfs(int v, int p) {
    if (p == -1) // if the node is root
        step[v] = 0; // which is the starting and has step of 0
    else
        step[v] = step[p] + 1; // the step is its parent + 1

    // same dfs template here
    for(int u : adj[v]){  // Iterate through neighbours
        if (u == p) continue;  // if neighbour node is parent, skip
        dfs(u, v);  // proceed to next level depth
    }
}

void solve() {
    int n; cin >> n;
    step = new int[n]; // Reset the steps step array
    memset(step, 0, n * sizeof(*step)); // Reset steps to 0; Optional because every node is reachable and we know the starting node's step

    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); // 0 indexed
        adj[v].push_back(u);
    }

    dfs(1, -1); // Start at any node

    // Trace back which node is furthest away
    int largest_step = -1, node;
    for (int i = 0; i < n; i++){
        if (step[i] > largest_step){
            largest_step = step[i];
            node = i;
        }
    }

    // DFS again
    step = new int[n];
    memset(step, 0, n * sizeof(*step));
    dfs(node, -1);

    // This time the furthest distance is the diameter (so no need to keep track of node)
    int diameter = 0;
    for (int i = 0; i < n; i++){
        diameter = max(diameter, step[i]);
    }

    cout << diameter << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
