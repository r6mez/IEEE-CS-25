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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));
    pair<int, int> start, end;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 'A') start = {i, j};
            else if (graph[i][j] == 'B') end = {i, j};
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> direction(n, vector<char>(m, '-'));
    queue<pair<int, int>> q;
    
    q.push(start);
    visited[start.first][start.second] = true;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};
    
    bool found = false;
    
    while (!q.empty() && !found) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && graph[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                direction[nx][ny] = dir[i];
                q.push({nx, ny});
                
                if (graph[nx][ny] == 'B') {
                    found = true;
                    break;
                }
            }
        }
    }
    
    if (visited[end.first][end.second]) {
        cout << "YES\n";
        string path;
        for (pair<int, int> at = end; at != start; at = parent[at.first][at.second]) {
            path.push_back(direction[at.first][at.second]);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }
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

