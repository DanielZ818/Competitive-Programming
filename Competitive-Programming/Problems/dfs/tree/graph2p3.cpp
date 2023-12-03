// Tree, DFS, Component implementation - find the edge require to form a tree within components
// Graph Contest 2 P3 - Trees
// https://dmoj.ca/problem/graph2p3
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

int n;
int MAX = 1001;
vector<VI> adj(MAX);
VI visited(MAX);
VI component;

void dfs(int u){
    component.push_back(u);
    visited[u] = true;
    for (auto v: adj[u]){
        if (!visited[v])
            dfs(v);
    }
}


void solve() {
    cin >> n;
    int edges = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int a; cin >> a;
            if (a) {
                adj[i].push_back(j);
                edges++;
            }
        }
    }
    edges /= 2;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
        ans += max(0, (int) component.size() - 1);
        component.clear();
    }
    cout << edges - ans << endl;
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
