/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// Monsters
// URL: https://vjudge.net/problem/CSES-1194
// Time: 1/25/2025, 12:04:27 AM
#include <bits/stdc++.h>
using namespace std;
#define ll   long long
#define vi   vector<int>
#define vll  vector<ll>
#define pll  pair<ll, ll>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;
 
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
char dir[] = { 'U', 'D', 'L', 'R' };
 
 
void Ramez() {
    int n, m; cin >> n >> m;
    vector<string> grid(n); cin >> grid;
 
    queue<pair<int, int>> q;
    int x, y; // start
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'M')
                q.push({ i,j });
            else if (grid[i][j] == 'A')
                x = i, y = j;
 
 
    q.push({ x, y });
 
    vector<vi> next(1005, vi(1005, 0));
    next[x][y] = -1;
 
    while (!q.empty()) {
        auto it = q.front();
        x = it.first; y = it.second;
        q.pop();
 
        // valid
        if (grid[x][y] == 'A' && (x == 0 || x == n - 1 || y == 0 || y == m - 1)) {
            cout << "YES" << endl;
            string ans;
            int d = next[x][y];
            while (d != -1) {
                ans += dir[d];
                x -= dx[d];
                y -= dy[d];
                d = next[x][y];
            }
 
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            cout << ans;
            return;
        }
 
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i], newY = y + dy[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= m || grid[newX][newY] != '.') continue;
 
            grid[newX][newY] = grid[x][y];
            if (grid[newX][newY] == 'A') next[newX][newY] = i;
            q.push({ newX, newY });
        }
    }
 
    cout << "NO";
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