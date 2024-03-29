// DFS find components of graph
// Find which nodes are connected
// CPC '21 Contest 1 P4 - AQT and Directed Graph
// https://dmoj.ca/problem/cpc21c1p4

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

vector<vector<int>> adj;
vector<bool> visited;   // Visited array
vector<int> best;


void dfs(int v, int par) {
    visited[v] = true;  // Set current node as visited
    for (int u : adj[v]) {  // Loop through all the neighbour, iterate to next one only if all depth has proceeded
        if (best[u] != -1 or visited[u])  continue;
        if (u < par)
            best[u] = par;
        dfs(u, par);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    best.resize(n + 1, -1);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[v].push_back(u);
    }

    for (int i = n; i >= 1; i--){
        dfs(i, i);
    }

    PII ans = {-1, -1};
    for(int i = 1; i <= n; i++)
        if (best[i] != -1) ans = max(ans, {i, best[i]});
    if (ans == make_pair(-1, -1)) {
        cout << -1 << endl;
        return;
    }

    cout << ans.first << " " << ans.second << endl;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
