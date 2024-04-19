#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))

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
    ll H, W, M;
    cin >> H >> W >> M;
    vector<ll> T(M), A(M), X(M);
    rep(i, M) cin >> T[i] >> A[i] >> X[i];

    // HxWのグリッド
    vector<vector<ll>> G(H, vector<ll>(W, 0));
    rep(i, M) {
        if (T[i] == 1) rep(w,W) G[A[i]-1][w] = X[i];  // 行の値を置き換える
        else           rep(h,H) G[h][A[i]-1] = X[i];  // 列の値を置き換える
    }

    map<ll,ll> mp;
    mp[0] = 0;
    rep(i,M) mp[X[i]] = 0;
    rep(i,H) {
        rep(j,W) {
            mp[G[i][j]] = mp[G[i][j]]+1;
        }
    }

    ll count = 0;
    rep(i,M) if (mp[X[i]] != 0) count++;
    cout << count << endl;

    sort(X.begin(), X.end());

    if (mp[0] != 0) cout << 0 << ' ' << mp[0] << endl;
    rep(i, M) {
        if (mp[X[i]] == 0) continue;
        cout << X[i] << ' ' << mp[X[i]] << endl;
    }
    return 0;
}
