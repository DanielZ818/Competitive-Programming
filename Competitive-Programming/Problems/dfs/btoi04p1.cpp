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


vector<vector<bool>> grid;
vector<vector<bool>> visited;
int n;

void dfs(int x, int y){
    visited[x][y] = true;
    PII directions[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto [i, j]: directions){
        int u = x + i, v = y + j;
        if (u >= 1 and v >= 1 and u < n and v < n and !visited[u][v])
            dfs(x, y);
    }

}


void solve() {
    cin >> n;
    grid.resize(n + 1, vector<bool>(n + 1));
    visited.resize(n + 1, vector<bool>(n + 1));

    cin.ignore(); // Clear the input buffer

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        if (line.empty()) {
            continue;
        }
        line = line.substr(0, line.size() - 1);
        size_t pos = 0;
        while ((pos = line.find(',')) != string::npos) {
            string token = line.substr(0, pos);
            line.erase(0, pos + 1);
            if (token.find('-') != string::npos) {
                size_t dashPos = token.find('-');
                int start = stoi(token.substr(0, dashPos));
                int end = stoi(token.substr(dashPos + 1));
                for (int k = start; k <= end; ++k) {
                    grid[i + 1][k] = true;
                }
            } else {
                grid[i + 1][stoi(token)] = true;
            }
        }
        if (!line.empty()) {
            if (line.find('-') != string::npos) {
                size_t dashPos = line.find('-');
                int start = stoi(line.substr(0, dashPos));
                int end = stoi(line.substr(dashPos + 1));
                for (int k = start; k <= end; ++k) {
                    grid[i + 1][k] = true;
                }
            } else {
                grid[i + 1][stoi(line)] = true;
            }
        }
    }

    map<int, int> ans;
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            if (grid[i][j] == true and !visited[i][j]){
                visited.resize(n+1, vector<bool>(n+1));
                int size = 0;
                dfs(i, j);
                for (auto k: visited)
                    for (auto l: k)
                        if (l) size++;
                if (ans.contains(size))
                    ans[size]++;
                else ans[size] = 0;
            }
        }
    }

    for (auto [i, j] : ans){
        cout << i << " " << j << endl;
    }

    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}

