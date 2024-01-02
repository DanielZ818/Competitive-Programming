// Dijkstra
// CSES Flight Discount
// https://cses.fi/problemset/task/1195
// ans https://pastebin.com/Fpk9v9Es
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
#define INFLL (ll) 7e18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n'
typedef long long ll;
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

struct Edge {
    ll dest;
    ll cost;

    Edge(ll dest, ll cost) : dest(dest), cost(cost) {}
};

struct Node {
    ll node;
    ll cost;
    ll state; // 1 used, 0 haven't used

    Node(ll node, ll cost, ll state) : node(node), cost(cost), state(state) {}

    bool operator<(const Node &other) const {
        return cost > other.cost; // Sort based on cost from min to max
    }
};


vector<vector<Edge>> adj;
vector<vector<ll>> costs; // costs[node][0] = its costs previously did not use discount; [1] = already use

void dijkstra(int start) {
    set<Node> priority_queue;

    Node start_node = Node(start, 0, 0);
    priority_queue.insert(start_node);
    costs[start][0] = 0;

    while (!priority_queue.empty()) {
        Node cur = *priority_queue.begin();
        priority_queue.erase(priority_queue.begin());

        // w = cur.cost, info = {cur.node, cur.state}

        for (auto neighbour: adj[cur.node]) {
            // u = neighbour.dest, weight = neighbour.cost
            if (cur.state == 1) {
                if (costs[neighbour.dest][1] > cur.cost + neighbour.cost) {
                    priority_queue.erase(Node(neighbour.dest, costs[neighbour.dest][1], 1));
                    costs[neighbour.dest][1] = cur.cost + neighbour.cost;
                    priority_queue.insert(Node(neighbour.dest, costs[neighbour.dest][1], 1));
                }
            }

            else {
                if (costs[neighbour.dest][0] > neighbour.cost + cur.cost) {
                    priority_queue.erase(Node(neighbour.dest, costs[neighbour.dest][0], 0));
                    costs[neighbour.dest][0] = neighbour.cost + cur.cost;
                    priority_queue.insert(Node(neighbour.dest, costs[neighbour.dest][0], 0));
                }

                if (costs[neighbour.dest][1] > (neighbour.cost / 2) + cur.cost) {
                    priority_queue.erase(Node(neighbour.dest, costs[neighbour.dest][1], 1));
                    costs[neighbour.dest][1] = (neighbour.cost / 2) + cur.cost;
                    priority_queue.insert(Node(neighbour.dest, costs[neighbour.dest][1], 1));
                }
            }
        }
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    costs.resize(n + 1, vector<ll>(2, INFLL));

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
    }

    ll start = 1, end = n;
    dijkstra(start);
    cout << min(costs[end][0], costs[end][1]) << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 1; i++)
        solve();

    return 0;
}
