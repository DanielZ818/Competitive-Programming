// CCHESS - COSTLY CHESS
// https://www.spoj.com/problems/CCHESS/
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


int n = 8;
vector<vector<int>> dis(n + 1, VI(n + 1));  // Stored the minimum distance

void dijkstra(int start_x, int start_y) {

    dis.assign(n + 1, vector<int>(n + 1, INF)); // Set to inf
    vector<vector<bool>> marked(n + 1, vector<bool>(n + 1, false));

    dis[start_x][start_y] = 0;

    for (int i = 1; i <= n*n; i++) {
        PII v = {-1, -1};  // Minimum distance vertex to the source
        // Finding the minimum distance vertex to the source
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                if (!marked[j][k] and (v.first == -1 or dis[j][k] < dis[v.first][v.second]))  // -1 is the start
                    v = {j, k};
            }


        if (dis[v.first][v.second] == INF) break;

        marked[v.first][v.second] = true;

        // 2 row, 1 col
        // 2 col, 1 row
        vector<PII> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

        for (auto d: directions) {
            int new_x = v.first + d.first;
            int new_y = v.second + d.second;
            int cost = v.first * new_x + v.second * new_y;
            if (new_x >= 0 and new_x <= 8 and new_y >= 0 and new_y <= 8 and dis[v.first][v.second] + cost < dis[new_x][new_y]) {
                dis[new_x][new_y] = dis[v.first][v.second] + cost;
//                cout << "Updated " << new_x << ',' << new_y << " with " << dis[new_x][new_y] << endl;
            }
            else {
//                cout << "Skipping: " << new_x << "," << new_y << " cost "<< dis[v.first][v.second] + cost  << ' ' << dis[new_x][new_y] << endl;
            }

        }
    }
}




void solve() {
    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;

    dijkstra(start_x, start_y);
    cout << (dis[end_x][end_y] == INF ? -1 : dis[end_x][end_y]) << endl;


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(!cin.eof())
        solve();

    return 0;
}
