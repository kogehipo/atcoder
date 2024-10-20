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
    int a,b,c,d,e,f,g,h,i,j,k,l;
    cin >>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
    int flg = 0;

    // a:j, d:g
    if (j <= a) flg = 1;
    if (d <= g) flg = 2;

    // b:k, e:h
    if (k <= b) flg = 3;
    if (e <= h) flg = 4;

    // c:l, f:i
    if (l <= c) flg = 5;
    if (f <= i) flg = 6;

    if (flg == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    //cout << flg << endl;
    return 0;
}
