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

// 要素数3以上のmin/max（C++20から）例.min({1,2,3})
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
    int H,W; cin >>H>>W;
    int i,j; cin >>i>>j;
    i--; j--;
    vector<string> C(H); rep(k,H) cin >>C[k];
    string S; cin >>S;
    rep(k,S.size()) {
        if (S[k] == 'U' && i > 0   && C[i-1][j] != '#') i--;
        if (S[k] == 'D' && i < H-1 && C[i+1][j] != '#') i++;
        if (S[k] == 'L' && j > 0   && C[i][j-1] != '#') j--;
        if (S[k] == 'R' && j < W-1 && C[i][j+1] != '#') j++;
        //cout << i+1 << " " << j+1 << endl;
    }
    cout << i+1 << " " << j+1 << endl;
    return 0;
}