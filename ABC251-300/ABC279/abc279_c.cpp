#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

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
    int H, W;
    cin >> H >> W;
    vector<string> S(H), T(H);
    vector<int> cnt(H, 0);
    rep(i, H) {
        cin >> S[i];
        cnt[i] = std::count(all(S[i]), '#');
    }
    rep(i, H) {
        cin >> T[i];
        if (cnt[i] != std::count(all(T[i]), '#')) {
            cout << "No" << endl;
            return 0;
        }
    }
    //cout << "Pase 1" << endl;

    vector<string> s(W, string(H, ' ')), t(W, string(H, ' '));
    rep(i, H) {
        rep(j, W) {
            s[j][i] = S[i][j];
            t[j][i] = T[i][j];
        }
    }
    sort(all(s));
    sort(all(t));
    rep(i, W) {
        if (s[i] != t[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
