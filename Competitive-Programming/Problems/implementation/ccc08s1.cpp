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




void solve() {
    string city;
    int temp = 201;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string c;
        int t;
        iss >> c >> t;
        if (t < temp) {
            city = c;
            temp = t;
        }
    }

    cout << city << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 1; i++)
        solve();
    
    return 0;
}
