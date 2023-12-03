// Grid bfs implementation - can a node be visited
// https://dmoj.ca/problem/dwite07c2p3
// DWITE '07 R2 #3 - Floor Plan

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
map<int, PII> rooms;


void solve() {
    // 0 indexed!!!
    cin >> r >> c;
    grid.resize(r, vector<char>(c, 0));
    for (int i = 0; i < r; i++){
        string line; cin >> line;
        for (int j = 0; j < c; j++){
            char cur = line[j];
            if (cur >= '1' and cur <= '5'){
                rooms[cur] = {i, j};
            }
            grid[i][j] = cur;
        }
    }



    for (auto& [key, val] : rooms){
        PII start = {val.first, val.second};
        queue<PII> queue;

        queue.push(start);

        int ans = 1;

        while (!queue.empty()){
            PII cur = queue.front(); queue.pop();
            int cur_row = cur.first, cur_col = cur.second;
            PII directions[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
            for (auto dir: directions) {
                int x = cur_row + dir.first;
                int y = cur_col + dir.second;

                if (x < 0 or y < 0 or x >= r or y >= c) continue;
                if (grid[x][y] == '#') continue;
                queue.push({x, y});
                grid[x][y] = '#';
                ans++;
            }
        }
        if (ans > 1) ans--;
        cout << ans << endl;

    }



}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
