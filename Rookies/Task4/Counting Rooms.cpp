/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained was fields of dreamless solitude.
*/
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

void Ramez() {
    int n, m; cin >> n >> m;
    vector<string> x(n); cin >> x;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int counter = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (x[i][j] == '#' || visited[i][j]) continue;
 
            counter++;
            
            stack<pair<int, int>> s;
            s.push({ i,j });
            while (!s.empty())
            {
                auto [h, u] = s.top(); s.pop();
                if (h < 0 || h >= n || u < 0 || u >= m || x[h][u] == '#' || visited[h][u]) continue;
                else visited[h][u] = true;
                s.push({ h + 1, u });
                s.push({ h - 1, u });
                s.push({ h, u + 1 });
                s.push({ h, u - 1 });
            }
        }
    }
 
    cout << counter << "\n";
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

