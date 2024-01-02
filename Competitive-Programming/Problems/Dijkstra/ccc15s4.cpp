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

int k, m, n;
vector<vector<pair<int, PII>>> adj; // adj[at], to, cost, k
vector<vector<int>> dis; // distance[at][k], cost

void dijkstra(int start){
    dis.assign(n + 1, vector<int>(k + 1, INF));
    dis[start][k] = 0;

    set<pair<int, pair<int, int>>> q; // cost, at, k
    q.insert({0, make_pair(start, k)});

    while (!q.empty()) {
        int cur = q.begin()->second.first;
        int cur_cost = q.begin()->first;
        int cur_k = q.begin()-> second.second;
        q.erase(q.begin());

        for(auto edge: adj[cur]) {
            int to = edge.first;
            auto [cost, h] = edge.second;
            if (cur_k - h > 0 and dis[to][cur_k - h] > cost + cur_cost) {
                q.erase({cost, make_pair(to, h)});
                dis[to][cur_k - h] = cur_cost + cost;
                    q.insert({dis[to][cur_k - h], make_pair(to, cur_k - h)});
            }
        }
    }
}

void solve() {
    cin >> k >> n >> m;
    adj.resize(n + 1);
    dis.resize(n + 1);
    for (int i = 0 ; i < m ; i++){
        int u, v, w, y;
        cin >> u >> v >> w >> y;
        adj[u].push_back(make_pair(v, make_pair(w, y)));
        adj[v].push_back(make_pair(u, make_pair(w, y)));
    }

    int start, end; cin >> start >> end;
    dijkstra(start);
    int ans = INF;
    for (auto i: dis[end]) ans = min(i, ans);
    cout << (ans == INF ? -1 : ans) << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    return 0;
}
