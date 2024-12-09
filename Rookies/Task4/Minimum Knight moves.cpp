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
    string start, end; cin >> start >> end;
    int x1 = start[0] - 'a', y1 = start[1] - '0' - 1; // start position
    int x2 = end[0] - 'a', y2 = end[1] - '0' - 1;  // end position

    vector<vi> table(8, vi(8, -1));
    queue<pair<int, int>> q;

    table[y1][x1] = 0;
    q.push({y1, x1});

    int move_i[] = {2,  2, -2, -2, 1, -1,  1, -1};
    int move_j[] = {1, -1,  1, -1, 2,  2, -2, -2};

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        // If reached end
        if(i == y2 && j == x2){
            cout << table[i][j] << "\n";
            return;
        }

        // process childern
        for (int k = 0; k < 8; k++){
            int newI = i + move_i[k], newJ = j + move_j[k];
            if(newI >= 8 || newI < 0 || newJ >= 8 || newJ < 0) continue; // out of bound
            if(table[newI][newJ] != -1) continue; // visited before
  
            table[newI][newJ] = table[i][j] + 1;
            q.push({newI, newJ}); 
        }
    }
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

