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

    string S;
    cin >> S;

    int ans = 0;
    int _1 = 0, _2 = 0;
    rep(n, N) {
        if      (S[n] == '1') {
            _1++;
        }
        else if (S[n] == '2') {
            _2++;
        }
        else if (S[n] == '0' || n == N-1) {
            int a = _2;
            a += max(0, _1-M);
            ans = max(ans, a);
            _1 = 0;
            _2 = 0;
        }
        if (n == N-1) {
            int a = _2;
            a += max(0, _1-M);
            ans = max(ans, a);
        }
    }

    cout << ans << endl;
    return 0;
}
