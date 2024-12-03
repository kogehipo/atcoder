#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define coutf cout << fixed << setprecision(8)
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))

// 要素数3以上のmin/max（C++20から）
#define min std::ranges::min
#define max std::ranges::max

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
    int N,M; cin >>N>>M;
    vector<string> S(N); rep(i,N) cin >> S[i];
    vector<pair<int,int>> ans;
    rep(y,N-8) rep(x,M-8) {
        if (S[y  ].substr(x,4) == "###." &&
            S[y+1].substr(x,4) == "###." &&
            S[y+2].substr(x,4) == "###." &&
            S[y+3].substr(x,4) == "...." &&
            S[y+5].substr(x+5,4) == "...." &&
            S[y+6].substr(x+5,4) == ".###" &&
            S[y+7].substr(x+5,4) == ".###" &&
            S[y+8].substr(x+5,4) == ".###") {
            ans.push_back({y,x});
        }
    }
    rep(i,ans.size()) cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    return 0;
}