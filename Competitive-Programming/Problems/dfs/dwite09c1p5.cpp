// Dfs Cycle detection and determine the size of the cycle
// DWITE '09 R1 #5 - Running In Circles
// https://dmoj.ca/problem/dwite09c1p5
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
typedef map<int, int> MPII;
typedef unordered_map<int, int> UMPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

// Comment this out to not use DEBUG_MODE
 #define DEBUG_MODE
#ifdef DEBUG_MODE
ifstream DEBUG_IN("input.txt");
#define cin DEBUG_IN
#endif

const int MAX_N = 100 + 5;
unordered_set<int> nodes;
vector<int> visited(MAX_N, false);
vector<VI> adj(MAX_N);
VI parent (MAX_N);
vector<bool> flag;





void solve() {
    nodes.clear();
    visited.clear();
    adj.clear();
    parent.clear();
    visited.resize(MAX_N);
    adj.resize(MAX_N);
    parent.resize(MAX_N);
    


    int m; cin >> m;
    bool point_to_self = false;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        nodes.insert(u);
        nodes.insert(v);
        adj[u].push_back(v);
        if (u == v) point_to_self = true;
    }





    if (point_to_self) {
        cout << 1 << endl;
        return;
    }

    dfs(1, -1);



}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 5; i++)
        solve();

    return 0;
}