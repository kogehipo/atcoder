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
    ll N,M; cin >>N>>M;
    ll Sx,Sy; cin >>Sx>>Sy;
    map<ll,multiset<ll>> Xmap, Ymap;
    rep(i,N) {
        ll x, y; cin >>x>>y;
        Xmap[x].insert(y);
        Ymap[y].insert(x);
    }
    ll ans = 0;
    ll x = Sx, y = Sy;
    rep(i,M) {
        ll l, r;
        char D; ll C; cin >> D >> C;
        if (D == 'R' || D == 'L') {
            if (D == 'R') l = x, r = x + C, x += C;
            else          l = x - C, r = x, x -= C;
            if (Ymap.find(y) == Ymap.end()) continue;
            if (Ymap[y].empty()) continue;
            while(1) {
                auto it = Ymap[y].lower_bound(l);
                if (it == Ymap[y].end()) break;
                if (r < *it) break;
                Ymap[y].erase(it);
                Xmap[*it].erase(y);
                ans++;
            }
        } else {
            if      (D == 'U') l = y, r = y + C, y += C;
            else if (D == 'D') l = y - C, r = y, y -= C;
            if (Xmap.find(x) == Xmap.end()) continue;
            if (Xmap[x].empty()) continue;
            while(1) {
                auto it = Xmap[x].lower_bound(l);
                if (it == Xmap[x].end()) break;
                if (r < *it) break;
                Xmap[x].erase(it);
                Ymap[*it].erase(x);
                ans++;
            }
        }
    }
    cout << x << " " << y << " " << ans << endl;
    return 0;
}
