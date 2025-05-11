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
    vector<string> S(H); rep(i,H) cin >>S[i];
    int y, x;
    for(y=0; y<H; y++) for(x=0; x<W; x++) {
        if (S[y][x] == '#') continue;

        S[y][x] = '#';
        int l=x,r=x,t=y,b=y;
        while(0 < l   && S[y][l] == '#') l--;
        if (S[y][l] == '.') l++;
        while(r < W-1 && S[y][r] == '#') r++;
        if (S[y][r] == '.') r--;
        while(0 < t   && S[t][x] == '#') t--;
        if (S[t][x] == '.') t++;
        while(b < H-1 && S[b][x] == '#') b++;
        if (S[b][x] == '.') b--;
        if (l == r || t == b) {
            S[y][x] = '.';
            continue;
        }
        bool flag = true;
        range(i,t,b) range(j,l,r) {
            if (S[i][j] == '.') {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << y+1 << " " << x+1 << endl;
            return 0;
        }

        S[y][x] = '.';
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}
