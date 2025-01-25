/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// C. PolandBall and Forest
// URL: https://codeforces.com/problemset/problem/755/C
// Time: 1/25/2025, 7:52:13 PM
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

void dfs(int i, vector<vi> &graph, vector<bool> &vis){
    for(auto j : graph[i]){
        if(!vis[j]){
            vis[j] = true;
            dfs(j, graph, vis);
        }
    }
}


void Ramez() {
    int n; cin >> n;
    vector<vi> graph(n + 1); 
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }
    
    vector<bool> vis(n + 1);
    int counter = 0;
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            counter++;
            vis[i] = true;
            dfs(i, graph, vis);
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

