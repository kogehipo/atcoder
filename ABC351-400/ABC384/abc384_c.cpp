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
    //int a,b,c,d,e; cin >>a>>b>>c>>d>>e;
    vector<int> ten(5); rep(i,5) cin >>ten[i];
    vector<pair<int,int>> p(32);
    p[0] = {-1,0};
    range(i,1,31) {
        int point = 0;
        unsigned int mask = 0x20;
        rep(j,5) {
            mask = mask >> 1;
            if (i & mask) point += ten[j];
        }
        p[i].first = point;
        p[i].second = i;
    }
    sort(rall(p));

    //rep(i,31) cout << p[i].first << " : " << p[i].second << endl;
    //cout << endl;

    string ABCDE = "ABCDE";
    rep(i,31) {
        int name = p[i].second;
        unsigned int mask = 0x20;
        rep(k,5) {
            mask = mask >> 1;
            if (name & mask) cout << ABCDE[k];
        }
        cout << endl;
    }
    return 0;
}
