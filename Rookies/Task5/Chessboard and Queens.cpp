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

 
int n = 8;
 
bool can(int i, int j, vi &c, vi &r, vi &mainDiag, vi &antiDiag, vector<string> &a) {
    if(a[i][j] == '*') return false;
    if(r[i] || c[j] || mainDiag[i - j + n - 1] || antiDiag[i + j]) return false;
    return true;
}
 
ll calc(int i, vi &c, vi &r, vi &mainDiag, vi &antiDiag, vector<string> &a) {
    if(i == n) return 1;
    
    ll sum = 0;
    for (int j = 0; j < n; j++) {
        if(can(i, j, c, r, mainDiag, antiDiag, a)) {
            c[j] = r[i] = mainDiag[i - j + n - 1] = antiDiag[i + j] = 1;
            sum += calc(i + 1, c, r, mainDiag, antiDiag, a);
            c[j] = r[i] = mainDiag[i - j + n - 1] = antiDiag[i + j] = 0;
        }
    }
    
    return sum;
}
 

void Ramez() {
    vector<string> a(n);
    cin >> a;
    vi c(n), r(n), mainDiag(2 * n - 1), antiDiag(2 * n - 1);
    ll ans = calc(0, c, r, mainDiag, antiDiag, a);
    cout << ans << "\n";
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

