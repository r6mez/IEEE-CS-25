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
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

void Ramez() {
    int n, m; cin >> n >> m;
    vector<vi> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<string> newEdges;

    vector<bool> visited(n + 1);
    int lastEdge = 0;

    for (int i = 1; i <= n; i++) {
        if (lastEdge != 0 && visited[i] == false)
            newEdges.push_back(to_string(lastEdge) + " " + to_string(i));

        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int s = q.front(); q.pop();
            lastEdge = s;
            for (int u : graph[s]) {
                if (visited[u]) continue;
                visited[u] = true;
                q.push(u);
            }
        }
    }

    cout << newEdges.size() << "\n";
    for (int i = 0; i < newEdges.size(); i++) {
        cout << newEdges[i] << "\n";
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

