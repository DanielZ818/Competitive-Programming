// EZDIJKST - Easy Dijkstra Problem
// https://www.spoj.com/problems/EZDIJKST/en/
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


vector<vector<PII>> adj;
vector<int> dis;

void dijkstra(int start) {
    int n = adj.size();
    dis.assign(n + 1, INF); // Set to inf
    vector<bool> marked(n, false);

    dis[start] = 0;
    for (int i = 1; i <= n; i++) {
        int v = -1;  // Minimum distance vertex to the source
        // Finding the minimum distance vertex to the source
        for (int j = 1; j <= n; j++) {
            if (!marked[j] and (v == -1 or dis[j] < dis[v]))  // -1 is the start
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
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    adj.assign(n, {});
    dis.resize(n + 1);


    for (int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }


    int A, B; cin >> A >> B;
    dijkstra(A);


    if (dis[B] == INF)
        cout << "NO" << endl;
    else
        cout << dis[B] << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        solve();
    
    return 0;
}
