// BFS Grid implementation
// dwite08c1p3
// https://dmoj.ca/problem/dwite08c1p3

#include <bits/stdc++.h>
//namespace std {
//    template <>
//    struct hash<pair<char, char>> {
//        size_t operator()(const pair<char, char>& p) const {
//            return hash<char>()(p.first) ^ hash<char>()(p.second);
//        }
//    };
//}
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(var, start, end, incr) for (int var=start ; var<end ; var+=incr)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define fi first
#define se second
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



const int R = 10, C = 19;
char grid[10][C];

int bfs(int start_x, int start_y, int end_x, int end_y);

void solve() {
    map<pair<char, char>, int> storage; // Storage to store checked distance
    unordered_map<char, pair<int, int>> pos; // Store each letter position

    // Grid input
    for (int x = 0; x < R; x++) {
        string line; cin >> line;
        for (int y = 0; y < C; y++) {
            char letter = line.at(y); // get each char
            grid[x][y] = letter;
            if (letter == '.' or letter == '#') continue; // Skip if it is wall or path
            pos[letter] = MP(x, y); // add to pos (letter, (x,y))
        }
    }

    // query for storing schedule/plan
    vector<pair<char, char>> query[5];
    FOR (i, 0, 5, 1) {
        string line; cin >> line;

        // If there is only one letter
        if (line.length() == 1){
            query[i].PB(make_pair(line.at(0), line.at(0)));
            continue;
        }

        // Divide into sub plan (from letter A to B)
        FOR (at, 1, line.length(), 1){
            char pre = line.at(at-1), cur = line.at(at);
            query[i].PB(make_pair(pre, cur));
        }
    }

    // Process the query
    FOR (i, 0, 5, 1){
        int ans = 0;
        auto q = query[i]; // Current plan
        for (auto cur: q){
            // start, end is the first, second of each pair of sub plan
            char start = cur.fi, end = cur.se;
            int start_x = pos[start].fi, start_y = pos[start].se;
            int end_x = pos[end].fi, end_y = pos[end].se;

            int steps;
            if (storage.contains(cur)){ // Check if this sub plan has been processed
                steps = storage[cur];
                ans += steps;
            }

            // If not perform bfs to find step
            else {
                steps = bfs(start_x, start_y, end_x, end_y);
                ans += steps;
                storage[cur] = steps; // Store to storage
            }
        }


        cout << ans << endl;
    }

}

int bfs(int start_x, int start_y, int end_x, int end_y){
    if (start_x == end_x and start_y == end_y) return 0;
    bool visited[R][C];
    MEM(visited, false);
    queue<pair<int, int>> q;
    q.emplace(start_x, start_y);
    int steps = 0;
    while (!q.empty()) {
        int size = (int) q.size();
        steps++;
        for (int k = 0; k < size; k++) { // this size is how many neighbours does current have
            auto cur = q.front();
            q.pop();
            int cur_x = cur.first, cur_y = cur.second;
            int dir[][2] = {{0,  1},
                            {1,  0},
                            {-1, 0},
                            {0,  -1}};

            FOR(i, 0, 4, 1) {
                int x = cur_x + dir[i][0];
                int y = cur_y + dir[i][1];

                if (x < 0 || y < 0 || x >= R || y >= C) continue; // Check boundaries
                if (grid[x][y] == '#') continue;
                if (visited[x][y]) continue;

                q.emplace(x, y);
                visited[x][y] = true;

                if (x == end_x && y == end_y) {
                    return steps;
                }
            }
        }
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 1; i++)
        solve();

    return 0;
}
