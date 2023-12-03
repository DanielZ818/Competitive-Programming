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



// THIS IS FOR UNDIRECTED GRAPH
// FOR DIRECTED GRAPH I THINK U HAVE TO DFS ON EVERY NODE?
bool check_within_same_component(int u, int v);

int n, m; // n nodes, m edges
int start_node, end_node;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> sub_component;
vector<vector<int>> components;

void dfs(int u) {
    visited[u] = true;
    sub_component.push_back(u);
    for (auto v: adj[u]){
        if (v == end_node) return;
        if (visited[v]) continue;
        dfs(v);
    }
}


void solve() {
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1);
    for (int i=0; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Bi-directional?
    }

    for (int i = 1; i <= n; i++) {
        sub_component.clear();
        if (!visited[i]) dfs(i);
        components.push_back(sub_component);
    }

    // Given q queries
    int q; cin >> q;
    for (int i = 0; i < q; i++){
        cin >> start_node >> end_node;
        if (check_within_same_component(start_node, end_node)) cout << true;
        else cout << false;
    }
}


bool check_within_same_component(int u, int v){
    for (auto i: components){
        bool u_in = false, v_in = false;
        for (auto j: i){
            if (j == u) u_in = true;
            if (j == v) v_in = true;
            if (u_in and v_in) return true;
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
