/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// Kefa and Park
// URL: https://vjudge.net/problem/CodeForces-580C
// Time: 1/25/2025, 12:07:00 AM
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

 
int validPaths = 0;
int n, m;
 
void dfs(int s, int cats, vector<vi> &graph, vector<bool> &visited, vi &cated) {
    visited[s] = true;
 
    if(cated[s]) cats++;
    else cats = 0;
 
    if(cats > m) return;
 
    bool isLeaf = true;
    for (auto u : graph[s]) {
        if (!visited[u]) {
            isLeaf = false;
            dfs(u, cats, graph, visited, cated);
        }
    }
 
    if (isLeaf) validPaths++;
}
 
void solve() {
    cin >> n >> m;
    vi cated(n); cin >> cated;
    vector<vi> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
 
    //dfs
    vector<bool> visited(n);
    dfs(0, 0, graph, visited, cated);
    cout << validPaths;
}
 
/*
NOTES:
 
*/
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}