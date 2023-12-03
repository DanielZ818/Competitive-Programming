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
#define ll long long
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


tuple<long long, long long> fib(int n) {
    if (n == 0)
        return make_tuple(0, 1);
    else {
        auto [a, b] = fib(n / 2);
        long long c = a * (b * 2 - a);
        long long d = a * a + b * b;
        if (n % 2 == 0)
            return make_tuple(c, d);
        else
            return make_tuple(d, c + d);
    }
}

vector<long long> generate(long long max_last_term) {
    vector<long long> sequence;
    int n = 0;
    while (true) {
        auto [current, next] = fib(n);
        if (current >= max_last_term)
            break;
        sequence.push_back(current);
        n++;
    }
    return sequence;
}


int solve(const vector<ll>& fib, vector<vector<ll> >& dp, int i, int s, int target, int total_sum) {
    if (s == target && i == fib.size())
        return 1;

    if (i >= fib.size())
        return 0;

    if (dp[i][s + total_sum] != -1)
        return dp[i][s + total_sum];

    return dp[i][s + total_sum] = solve(fib, dp, i + 1, s + fib[i], target, total_sum)
                                + solve(fib, dp, i + 1, s - fib[i], target, total_sum);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int query[n];
    int mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> query[i];
        mx = max(mx, query[i]);
    }

    // query of targets
    for (auto i: query) cout << i << " ";
    cout << endl;
    cout << mx << endl;

    auto fib = generate(mx);
    fib.erase(fib.begin());

    // Fib
    for (auto i: fib) cout << i << " ";
    cout << endl;

    int total_sum = 0;
    for (int i = 0; i < fib.size(); i++)
        total_sum += fib[i];

    for (int i = 0; i < n; i++) {
        int tar;
        cin >> tar;
        vector<vector<int> > dp(fib.size(), vector<int>(2 * total_sum + 1, -1));
        cout << solve(dp, fib, 0, 0, tar, total_sum) << endl;
    }
    
    return 0;
}
