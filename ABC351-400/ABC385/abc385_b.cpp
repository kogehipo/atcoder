#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ld = long double;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (ll)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define coutf cout << fixed << setprecision(8)
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))

// 要素数3以上のmin/max（C++20から）例.min({1,2,3})
//#define min std::ranges::min
//#define max std::ranges::max

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

int main()
{
    int H,W,X,Y; cin >>H>>W>>X>>Y; X--; Y--;
    vector<string> S(H); rep(i,H) cin >>S[i];
    string T; cin >> T;
    int ans = 0;
    if (S[X][Y] == '@') { ans++; S[X][Y] = '.'; }
    rep(i,T.size()) {
        if (T[i] == 'L' && S[X][Y-1] != '#') Y--;
        if (T[i] == 'R' && S[X][Y+1] != '#') Y++;
        if (T[i] == 'U' && S[X-1][Y] != '#') X--;
        if (T[i] == 'D' && S[X+1][Y] != '#') X++;
        if (S[X][Y] == '@') { ans++; S[X][Y] = '.'; }
    }
    cout << X+1 << " " << Y+1 << " " << ans << endl;
    return 0;
}
