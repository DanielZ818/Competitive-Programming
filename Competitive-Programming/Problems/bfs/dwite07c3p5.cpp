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


int r, c;
vector<vector<char>> grid;
vector<pair<PII, PII>> position(10);
vector<PII> room(5);
vector<vector<bool>> visited;

int bfs(PII start){
    queue<PII> queue;
    queue.push(start);
    fill(visited.begin(), visited.end(), vector<bool>(c, false));
    visited[start.first][start.second] = true;

    while (!queue.empty()){
        PII cur = queue.front(); queue.pop();
        auto [x, y] = cur;
        PII directions[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [a, b]: directions){
            int u = a + x;
            int v = b + y;
            if (u >= 0 and u < r and v >= 0 and v < c and grid[u][v] != '#' and !visited[u][v]){
                visited[u][v] = true;
                queue.push({u, v});
                if (grid[u][v] >= 'a' and grid[u][v] <= 'j') {
                    auto [to_x, to_y] = position[grid[u][v]-'a'].second;
                    visited[to_x][to_y] = true;
                    queue.push({to_x, to_y});
                }

            }

        }


    }

    int ans = 0;
    for (auto i: visited) {
        for (auto j: i) {
            if (j) ans++;
        }
    }

    return ans;
}




void solve() {
    cin >> r >> c;
    grid.resize(r, vector<char>(c, 0));
    visited.resize(r, vector<bool>(c, false));
    fill(position.begin(), position.end(), MP(MP(-1, -1), MP(-1, -1)));

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            char cur; cin >> cur;
            grid[i][j] = cur;

            if (cur >= 'a' and cur <= 'j')
                position[cur - 'a'].first = {i, j};
            else if (cur >= 'A' and cur <= 'J')
                position[cur - 'A'].second = {i, j};
            if (cur >= '1' and cur <= '5')
                room[cur-'1'] = {i, j};
        }
    }
    for (auto i: room)
        cout << bfs(i) << endl;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
