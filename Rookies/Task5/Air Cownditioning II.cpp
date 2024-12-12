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

int calc(int i, int cost, vector<int> &barns, vector<int> &air, vector<vector<int>> &a) {
    if (i == a.size()) {
        for (int j = 0; j < barns.size(); j++) {
            if (barns[j] > air[j]) return INT_MAX;
        }
        return cost;
    }

    int notTake = calc(i + 1, cost, barns, air, a);

    vector<int> airIfTake(air);
    for (int j = a[i][0]; j <= a[i][1]; j++) {
        airIfTake[j] += a[i][2];
    }
    int take = calc(i + 1, cost + a[i][3], barns, airIfTake, a);

    return min(take, notTake);
}


void Ramez() {
    int cowsNum, ACs;
    cin >> cowsNum >> ACs;
    vi barns(101, 0), air(101, 0); 

    for (int i = 0; i < cowsNum; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        for (int j = l; j <= r; j++) {
            barns[j] = max(barns[j], t);
        }
    }

    vector<vector<int>> a(ACs, vi(4));
    for (int i = 0; i < ACs; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }

    int result = calc(0, 0, barns, air, a);
    cout << result << "\n";
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

