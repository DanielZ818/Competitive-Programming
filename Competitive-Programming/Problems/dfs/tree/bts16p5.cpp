// Tree implementation - Sub tree weight
// Back To School '16: Cherry Tree
// https://dmoj.ca/problem/bts16p5

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

int const MAX_N = 100010;

vector<int> parent(MAX_N);
vector<int> steps(MAX_N);
vector<int> cherry(MAX_N);
vector<vector<pair<int, int>>> weight(MAX_N);

void dfs(int v) {
    if (parent[v] == -1) // if the node is root
        steps[v] = 0; // which is the starting and has step of 0

    for (pair<int, int> u: weight[v]) {  // Iterate through neighbours
        if (u.first == parent[v]) continue;  // if neighbour node is parent, skip
        parent[u.first] = v;
        dfs(u.first);  // proceed to next level depth

        int neighbour_weight;
        for (auto i: weight[v]) {
            if (i.first == u.first) {
                neighbour_weight = i.second;
            }
        }
        steps[v] += steps[u.first] + neighbour_weight;
        cherry[v] += cherry[u.first];
    }

}


void solve() {
    int n, c, k;
    cin >> n >> c >> k;
    FOR(i, 1, n + 1, 1) cin >> cherry[i];
    FOR(i, 1, n, 1) {
        int u, v, w;
        cin >> u >> v >> w;
        weight[u].emplace_back(v, w);
        weight[v].emplace_back(u, w);
    }

    parent[1] = -1;
    steps[1] = 0;
    dfs(1);

    int ans = 0;
    for (int v = 2; v <= n; v++) {
        int parent_weight;
        for (auto i: weight[v])
            if (i.first == parent[v]) { parent_weight = i.second; break; }
        steps[v] += parent_weight;
        if (steps[v] <= k and cherry[v] >= c)
            ans ++;
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
