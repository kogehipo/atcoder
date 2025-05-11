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
    int xA,yA,xB,yB,xC,yC; cin >>xA>>yA>>xB>>yB>>xC>>yC;
    double xAB = abs(xB - xA);
    double yAB = abs(yB - yA);
    double xAC = abs(xC - xA);
    double yAC = abs(yC - yA);
    double xBC = abs(xC - xB);
    double yBC = abs(yC - yB);

    //cout << " " << xAB << " " << yAB << " " << xAC << " " << yAC << " " << xBC << " " << yBC << endl;
    //cout << yBC/xBC << " " << xAB/yAB << endl;
    //cout << yAC/xAC << " " << xAB/yAB << endl;
    //cout << yAC/xAC << " " << xBC/yBC << endl;

    if (yBC/xBC == xAB/yAB ||
        yAC/xAC == xAB/yAB ||
        yAC/xAC == xBC/yBC)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    return 0;
}
