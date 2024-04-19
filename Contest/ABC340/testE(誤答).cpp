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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N+1);
    vector<ll> B(M+1);

    rep(n, N) cin >> A[n];
    rep(m, M) cin >> B[m];

    ll C = 0;

    rep (i, M) {
        ll X = A[B[i]];
        A[B[i]] = 0;
        if (X == 0) continue;
        rep(x,X) {
            C++;
            A[(B[i]+C)%N]++;
        }
    }

    rep(n, N) {
        if (n) cout << ' ';
        cout << A[n];
    }
    cout << endl;
    return 0;
}
