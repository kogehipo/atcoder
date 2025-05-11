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

int H,W,D;

void dump(vector<string> &T)
{
    rep(y,H) {
        rep(x,W) cout << T[y][x];
        cout << endl;
    }
}

void mark(vector<string> &T, int Y, int X)
{
    range(y,Y-D,Y+D) range(x,X-D,X+D) {
        if (y < 0 || y >= H || x < 0 || x >= W) continue;
        if (abs(y-Y) + abs(x-X) > D) continue;
        if (T[y][x] != '#') T[y][x] = 'o';
    }
}

int main()
{
    cin >>H>>W>>D;
    vector<string> S(H); rep(i,H) cin >>S[i];
    int ans = 0;
    int y1,y2,x1,x2;
    range(y1,0,H-1) range(x1,0,W-1) {
        if (S[y1][x1] != '.') continue;
        vector<string> T; T = S;
        mark(T, y1, x1);
        range(y2,y1,H-1) range(x2,0,W-1) {
            if (y1 == y2 && x1 >= x2) continue;
            if (S[y2][x2] != '.') continue;
            //cout << y1 << " " << x1 << " " << y2 << " " << x2 << endl;
            vector<string> U; U = T;
            mark(U, y2, x2);
            int cnt = 0;
            rep(y,H) rep(x,W) if (U[y][x] == 'o') cnt++;
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
