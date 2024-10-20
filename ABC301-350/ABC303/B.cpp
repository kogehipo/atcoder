#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

// ここから下はオプション。問題によって選択すること。

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}

//---------------------------------------------------
// 問題 
// 解説 


int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> x(N, vector<bool>(N, false));

    rep(i, N) {
        range(j, 0, i) {
            x[i][j] = true;
        }
    }
/*
    range(i, 0, N-1) {
        range(j, 0, N-1) {
            cout << x[i][j] << ' ';
        }
        cout << endl;
    }
*/
    rep(m, M) {
        vector<int> data(N);
        rep(n, N) cin >> data[n];
        rep(n, N-1) {
            int a = min((int)data[n], (int)data[n+1]);
            int b = max((int)data[n], (int)data[n+1]);
            x[a-1][b-1] = true;
        }
    }
/*
    range(i, 0, N-1) {
        range(j, 0, N-1) {
            cout << x[i][j] << ' ';
        }
        cout << endl;
    }
*/
    int ans = 0;
    rep(i, N) {
        rep(j, N) {
            if (!x[i][j]) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
