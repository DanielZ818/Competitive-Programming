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
//#define DEBUG_MODE
#ifdef DEBUG_MODE
    ifstream DEBUG_IN("input.txt");
    #define cin DEBUG_IN
#endif


vector<vector<int>> adj;
vector<int> steps;
int end_node1 = -1, end_node2 = -1;
vector<int> steps_from_end_node1;
vector<int> steps_from_end_node2;

void dfs(int v, int p){
    if (p == -1) steps[v] = 0;
    else steps[v] = steps[p] + 1;
    for(int u : adj[v]){  // Iterate through neighbours
        if (u == p) continue;  // if neighbour node is parent, skip
        dfs(u, v);  // proceed to next level depth
    }
}

void dfs1(int v, int p){
    if (p == -1) steps_from_end_node1[v] = 0;
    else steps_from_end_node1[v] = steps_from_end_node1[p] + 1;
    for(int u : adj[v]){  // Iterate through neighbours
        if (u == p) continue;  // if neighbour node is parent, skip
        dfs1(u, v);  // proceed to next level depth
    }
}

void dfs2(int v, int p){
    if (p == -1) steps_from_end_node2[v] = 0;
    else steps_from_end_node2[v] = steps_from_end_node2[p] + 1;
    for(int u : adj[v]){  // Iterate through neighbours
        if (u == p) continue;  // if neighbour node is parent, skip
        dfs2(u, v);  // proceed to next level depth
    }
}

void solve() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    steps.resize(n + 1);
    dfs(1, -1);
    int largest_step = -1;
    for (int i = 1; i <= n; i++){
        if (steps[i] > largest_step){
            largest_step = steps[i];
            end_node1 = i;
        }
    }

    fill(steps.begin(), steps.end(), 0);
    dfs(end_node1, -1);
    largest_step = -1;
    for (int i = 1; i <= n; i++){
        if (steps[i] > largest_step){
            largest_step = steps[i];
            end_node2 = i;
        }
    }

    steps_from_end_node1.resize(n+1);
    steps_from_end_node2.resize(n+1);
    dfs1(end_node1, -1);
    dfs2(end_node2, -1);

    for(int i = 1; i <= n; i++){
        cout << max(steps_from_end_node1[i], steps_from_end_node2[i]) << " ";
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
