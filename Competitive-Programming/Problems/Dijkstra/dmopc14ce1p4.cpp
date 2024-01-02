// DMOPC '14 Exam Time P4 - Exam Delay
// https://dmoj.ca/problem/dmopc14ce1p4

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


vector<vector<pair<int, double>>> adj;
vector<int> cost;
vector<int> intersection;

//void dijkstra() {
//
//    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
//    pq.push({0, 1});
//    cost[1] = 0, intersection[1] = 0;
//
//    while (!pq.empty()) {
//        auto [cur_weight, at] = pq.top(); pq.pop();
//        if (cur_weight != cost[at]) continue;
//
//        for (auto [neighbour, w]: adj[at]) {
//            double new_cost = w + cur_weight;
//            if (cost[neighbour] > new_cost or (cost[neighbour] == new_cost and intersection[neighbour] >= intersection[at] + 1)) {
//                pq.push({new_cost, neighbour});
//                cost[neighbour] = new_cost;
//                intersection[neighbour] = intersection[at] + 1;
//            }
//        }
//    }
//
//}



void dijkstra() {
    set<pair<double, int>> priority_queue;
    priority_queue.insert({0, 1});
    cost[1] = 0;
    intersection[1] = 0;

    while (!priority_queue.empty()) {
        auto [cur_cost, cur_node] = *priority_queue.begin();
        priority_queue.erase(priority_queue.begin());
        int cur_intersection = intersection[cur_node];

        for (auto [neighbour_node, neighbour_cost]: adj[cur_node]) {
            if ((cost[neighbour_node] > cur_cost + neighbour_cost) or (cost[neighbour_node] == cur_cost + neighbour_cost and intersection[neighbour_node] > cur_intersection + 1)) {
                priority_queue.erase({cost[neighbour_node], neighbour_node});

                cost[neighbour_node] = cur_cost + neighbour_cost;
                priority_queue.insert({cost[neighbour_node], neighbour_node});
                intersection[neighbour_node] = cur_intersection + 1;
            }
        }
    }
}


void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    cost.resize(n + 1, INF);
    intersection.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v, w, x; cin >> u >> v >> w >> x;
        adj[u].push_back({v, (double) w / x * 60});
    }



    dijkstra();

    cout << intersection[n] << endl;
    cout << cost[n]/3 << endl;


};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 1; i++)
        solve();

    return 0;
}
