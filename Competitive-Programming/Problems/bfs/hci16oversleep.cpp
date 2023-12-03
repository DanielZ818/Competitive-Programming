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


vector<vector<char>> grid;
vector<VI> visited;
vector<VI> steps;

void solve() {
    int r, c; cin >> r >> c;
    PII start, end;
    grid.resize(r, vector<char>(c)), visited.resize(r, VI(c, 0));
    steps.resize(r, VI(c));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            char cur; cin >> cur;
            grid[i][j] = cur;
            if (cur == 's') start = {i, j};
            if (cur == 'e') end = {i, j};
        }
    }


    queue<PII> queue;
    visited[start.first][start.second] = true;
    steps[start.first][start.second] = 0;
    queue.push(start);

    while (!queue.empty()){
        PII cur = queue.front(); queue.pop();
        auto [x, y] = cur;
        PII directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [a, b]: directions){
            int u = a + x, v = b + y;
            if (u >= 0 and u < r and v >= 0 and v < c and !visited[u][v] and grid[u][v] != 'X') {
                if (MP(u, v) == end){
                    cout << steps[x][y] << endl;
                    return;
                }
                visited[u][v] = true;
                steps[u][v] = steps[x][y] + 1;
                queue.push({u, v});
            }

        }
    }
    cout << "-1" << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
