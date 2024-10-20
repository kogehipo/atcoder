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
    int R, C;
    cin >> R >> C;
    vector<string> B(R);
    rep(i, R) cin >> B[i];
    rep(r, R) {
        rep(c, C) {
            if (B[r][c] == '.') continue;
            if (B[r][c] == '#') continue;
            int M = B[r][c] - '0';
            int i = r;
            int j = c;
            range (i, r-M, r+M) {
                range (j, c-M, c+M) {
                    if (i < 0 || R <= i) continue;
                    if (j < 0 || C <= j) continue;
                    if (B[i][j] != '.' && B[i][j] != '#') continue;
                    if (abs(i-r) + abs(j-c) <= M) B[i][j] = '.';
                }
            }
            B[r][c] = '.';
        }
    }
    rep(i, R) cout << B[i] << endl;
    return 0;
}
