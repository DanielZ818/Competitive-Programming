// CSES Problem Set - Flight Routes
// https://cses.fi/problemset/task/1196
// https://pastebin.com/GzfWACHQ

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
typedef long long ll;


// Comment this out to not use DEBUG_MODE
//#define DEBUG_MODE
#ifdef DEBUG_MODE
    ifstream DEBUG_IN("input.txt");
    #define cin DEBUG_IN
#endif




void solve() {
    ll n, m, k; cin >> n >> m >> k;

    vector<vector<pair<ll, ll>>> adj(n+1);
    vector<priority_queue<ll>> cost(n+1);


    for (ll i = 1; i <= m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }


    // **priority using vector<> and greater<> significantly impact performance
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;  // {cost, at}

    cost[1].push(0);
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cur_weight, at] = pq.top(); pq.pop();
        if (cur_weight > cost[at].top()) continue;

        for (auto [neighbour, w]: adj[at]) {
            ll new_weight = w + cur_weight;
            if (cost[neighbour].size() < k) {
                cost[neighbour].push(new_weight);
                pq.push({new_weight, neighbour});
            }
            else if(cost[neighbour].top() > new_weight) {
                cost[neighbour].pop();
                cost[neighbour].push(new_weight);
                pq.push({new_weight, neighbour});
            }
        }
    }


    vector<ll> ans;
    while (!cost[n].empty()) {
        ans.push_back(cost[n].top());
        cost[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for(auto i: ans) {
        cout << i << ' ';
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
