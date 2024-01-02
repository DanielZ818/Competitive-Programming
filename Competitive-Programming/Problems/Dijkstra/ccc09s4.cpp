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
vector<vector<PII>> adj;
vector<int> dis;

void dijkstra(int start) {
    vector<bool> marked(n, false);
    dis.assign(n+1, INF);

    dis[start] = 0;
    for (int i = 1; i <= n; i++) {
        int v = -1;  // Minimum distance vertex to the source
        for (int j = 1; j <= n; j++) {
            if (!marked[j] and (v == -1 || dis[j] < dis[v]))
                v = j;
        }

        if (dis[v] == INF)
            break;

        marked[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;

            }
        }
    }
}




void solve() {
    cin >> n >> m;
    adj.resize(n+1);
    dis.resize(n+1, INF);
    for (int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

    }

    vector<PII> pencils;
    int k; cin >> k;
    for (int i = 1; i <= k; i++) {
        int v, c; cin >> v >> c;
        pencils.push_back({v, c});

    }

    int D; cin >> D;
    dijkstra(D);

    int ans = INF;
    for (auto i: pencils){
        ans = min(ans, dis[i.first] + i.second);
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
