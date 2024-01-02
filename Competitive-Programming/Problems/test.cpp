#include <bits/stdc++.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

// Comment this out to not use DEBUG_MODE
#define DEBUG_MODE
#ifdef DEBUG_MODE
    ifstream DEBUG_IN("input.txt");
    #define cin DEBUG_IN
#endif


vector<vector<int>> adj;
vector<vector<int>> reversed_adj;
vector<bool> visited;   // Visited array
vector<bool> sub_visited;
vector<int> component; // Break tree into components
int max_x = -1, max_y = -1;

void dfs(int v) {
    component.push_back(v);
    visited[v] = true;  // Set current node as visited
    for (int u : adj[v]) {  // Loop through all the neighbour, iterate to next one only if all depth has proceeded
        if (!visited[u])    // If the neighbor is not visited (otherwise infinite loop)
            dfs(u); // Call dfs on the neighbours
    }
}

void rev_dfs(int v) {
    sub_visited[v] = true;  // Set current node as visited
    for (int u : reversed_adj[v]) {  // Loop through all the neighbour, iterate to next one only if all depth has proceeded
        if (!sub_visited[u])    // If the neighbor is not visited (otherwise infinite loop)
            rev_dfs(u); // Call dfs on the neighbours
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj.resize(n+1, vector<int>(n+1));
    reversed_adj.resize(n+1, vector<int>(n+1));
    sub_visited.resize(n+1);
    visited.resize(n+1);

    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        reversed_adj[v].push_back(u);
    }


    for(int i = 1 ; i <= n; i++){
        component.clear();
        if (!visited[i]) dfs(i);
        sort(component.rbegin(), component.rend());
        if (component.empty()) continue;
        for (auto u: component){
            fill(sub_visited.begin(), sub_visited.end(), false);
            rev_dfs(u);
            vector<int> reached;
            for (int k = 1; k <= n; k++){
                if (sub_visited[k]) reached.push_back(k);
            }
            if (reached.size() > 1) {
                int y = u, x = -1;
                for (auto k: reached)
                    if (k != u){
                        x = max(x, k);
                    }
                if (x > max_x)
                    max_x = x, max_y = y;
                break;
            }
        }
    }

    cout << min(max_x, max_y) << " " << max(max_x, max_y) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 1; i++)
        solve();

    return 0;
}
