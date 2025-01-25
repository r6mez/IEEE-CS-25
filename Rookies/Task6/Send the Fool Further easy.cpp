/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// J. Send the Fool Further! (easy)
// URL: https://codeforces.com/problemset/problem/802/J
// Time: 1/25/2025, 6:40:32 PM
#include <bits/stdc++.h>
using namespace std;
#define ll   long long
#define vi   vector<int>
#define vll  vector<ll>
#define pll  pair<ll, ll>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){ for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v){ for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;
const int  dx[]  = { -1,   1,   0,   0  };
const int  dy[]  = {  0,   0,  -1,   1  };
const char dir[] = { 'U', 'D', 'L', 'R' };

ll dfs(int i, vector<vector<pair<int, int>>> &a, vector<bool> &vis) {
    vis[i] = true;
    ll maxCost = 0;

    for (const auto &neighbor : a[i]) {
        int v = neighbor.first;
        int c = neighbor.second;
        if (!vis[v]) {
            maxCost = max(maxCost, dfs(v, a, vis) + c);
        }
    }

    vis[i] = false; 
    return maxCost;
}

void Ramez() {
    int n; 
    cin >> n;
    vector<vector<pair<int, int>>> a(n);
    vector<bool> vis(n, false);

    for (int i = 0; i < n-1; i++) {
        int u, v, c; 
        cin >> u >> v >> c;
        a[u].push_back({v, c});
        a[v].push_back({u, c});
    }

    ll maxCost = dfs(0, a, vis);
    cout << maxCost << endl;
}

/*
NOTES:

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

