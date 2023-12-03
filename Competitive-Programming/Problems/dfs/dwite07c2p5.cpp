// DFS - Find if an edge decides connectivity
// DWITE '07 R2 #5 - Bridges In A Graph
// https://dmoj.ca/problem/dwite07c2p5

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
#define DEBUG_MODE
#ifdef DEBUG_MODE
    ifstream DEBUG_IN("input.txt");
    #define cin DEBUG_IN
#endif

int n, m;
vector<VI> adj;
vector<bool> visited;

void dfs(int v){
    visited[v] = true;
    for (auto u: adj[v]){
        if (!visited[u])
            dfs(u);
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1);

    queue<PII> queue;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        queue.push({u, v});
    }


    int ans = 0;
    while (!queue.empty()){
        auto [u, v] = queue.front(); queue.pop();
        auto it = std::find(adj[u].begin(), adj[u].end(), v);
        adj[u].erase(it);
        dfs(1);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                ans++;
                break;
            }
        }
        fill(visited.begin(), visited.end(), false);
        adj[u].push_back(v);
    }

    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
