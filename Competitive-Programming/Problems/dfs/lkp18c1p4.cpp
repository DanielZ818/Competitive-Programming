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
#define INFLL (ll)7e18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n'
typedef long long ll;
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

vector<vector<pair<ll, pair<ll, ll>>>> adj;
vector<vector<ll>> paths;

void findPathsDFS(ll start, ll end, ll weightLimit, ll currentWeight, vector<ll>& path, vector<bool>& visited) {
    visited[start] = true;
    path.push_back(start);

    if (start == end && currentWeight < weightLimit) {
        paths.push_back(path);
    } else {
        for (const auto& neighbor : adj[start]) {
            ll nextNode = neighbor.first;
            ll weight = neighbor.second.first;

            if (!visited[nextNode] && currentWeight + weight < weightLimit) {
                findPathsDFS(nextNode, end, weightLimit, currentWeight + weight, path, visited);
            }
        }
    }

    // Backtrack
    path.pop_back();
    visited[start] = false;
}


void solve() {
    ll n, m;
    cin >> n >> m;
    adj.resize(n+1);

    for (ll i = 1; i <= m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, {w, i}});
        adj[v].push_back({u, {w, i}});
    }

    ll a, b, c; cin >> a >> b >> c;

    vector<bool> visited(n + 1, false);
    vector<ll> path;
    findPathsDFS(a, b, c, 0, path, visited);

    ll ans = INFLL;
    for (auto i: paths) {
        ll pass = 0;
        for (ll j = 0; j < i.size() - 1; j++) {
            int start = i[j], end = i[j + 1];
            for (auto k: adj[start]) {
                if (k.first == end) pass = max(pass, k.second.second);
            }
        }
        ans = min(pass, ans);
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
