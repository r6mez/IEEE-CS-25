/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// A - The Lakes
// URL: https://vjudge.net/contest/670433#problem/A
// Time: 1/25/2025, 5:49:08 PM
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

int dfs(int i, int j, int n, int m, vector<vi> &a, vector<vector<bool>> &visited){
    if (i < 0 || i >= n || j < 0 || j >= m || !a[i][j] || visited[i][j]) return 0;

    visited[i][j] = true;

    int total = 0;
    for (int k = 0; k < 4; k++){
        total += dfs(i + dx[k], j + dy[k], n, m, a, visited);
    }

    return total + a[i][j];
}

void Ramez() {
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));
    for(vi &x : a) cin >> x;

    vector<vector<bool>> visited(n, vector<bool>(m));

    int maxVol = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            maxVol = max(maxVol, dfs(i , j, n, m, a, visited));
        }
    }
    
    cout << maxVol << "\n";
}

/*
NOTES:

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

