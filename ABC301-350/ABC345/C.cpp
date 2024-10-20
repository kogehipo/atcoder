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

// 1+2+...+N の合計を返す(nC2を計算)
ll f(ll N) {
    ll ret = N*(N-1)/2;
    return ret;
}

int main()
{
    string S;
    cin >> S;
    ll N = S.size();

    // すべての文字が異なる場合
    ll ans = f(N);
    //cout << "max=" << ans << endl;

    vector<ll> count(26, 0);
    for (ll i=0; i<N; i++) count[S[i]-'a']++;

    bool flag = false;
    rep(i,26) {
        if (1<count[i]) {  // 同じ文字が2個以上ある場合（元と同じ文字列になる）
            ll x = f(count[i]);
            ans = ans - f(count[i]);
            flag = true;
        }
    }

    if (flag) ans++;  // 元の文字列そのものはカウント必要
    cout << ans << endl;
    return 0;
}
