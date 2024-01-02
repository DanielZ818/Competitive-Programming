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
#define INF (long long)1e15
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


vector<vector<pair<long long, long long>>>adj;
vector<long long> dis;

void dijkstra(int start) {
    dis.assign(dis.size(), INF);
    dis[start] = 0;
    set<pair<long long, long long>> priority_queue;
    priority_queue.insert({0, start});

    while (!priority_queue.empty()){
        long long cur = priority_queue.begin()->second;
        priority_queue.erase(priority_queue.begin());

        for (auto edge: adj[cur]) {
            long long to = edge.first;
            long long cost = edge.second;

            if (dis[cur] + cost < dis[to]) {
                priority_queue.erase({dis[to], to});
                dis[to] = dis[cur] + cost;
                priority_queue.insert({dis[to], to});
            }
        }
    }
}


void solve() {
    long long n, m; cin >> n >> m;
    adj.resize(n+1);
    dis.resize(n+1);

    for (long long i = 1; i <= m; i++) {
        long long u , v , w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(1);
    for (long long i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
