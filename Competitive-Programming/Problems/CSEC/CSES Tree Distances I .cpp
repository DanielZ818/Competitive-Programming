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


vector<vector<int>> adj;
vector<int> steps;

void dfs(int v, int p){
    if (p == -1) steps[v] = 0;
    else steps[v] = steps[p] + 1;
    for(int u : adj[v]){  // Iterate through neighbours
        if (u == p) continue;  // if neighbour node is parent, skip
        dfs(u, v);  // proceed to next level depth
    }
}

void solve() {
    cout << "Solving" << endl;
    int n; cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++){
        steps.resize(n+1, 0);
        dfs(i, -1);
        int ans = -1;
        for (auto j: steps) ans = max(ans, j);
        cout << ans << ' ';
    }
    cout << endl;

    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
