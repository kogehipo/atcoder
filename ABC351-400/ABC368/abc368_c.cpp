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

int main()
{
    int N; cin >>N;
    vector<int> H(N); rep(i,N) cin >> H[i];
    ll T = 0;
    rep(i,N) {
        int t = T%3;
        while(t != 0) {
            if (t == 1) {
                H[i]--;
                T++;
                if (H[i] <= 0) break;
                t = T%3;
            } else if (t == 2) {
                H[i] -= 3;
                T++;
                if (H[i] <= 0) break;
                t = T%3;
            }
        }
        if (H[i] <= 0) continue;
        T += (H[i]/5)*3;
        H[i] = H[i]%5;
        if      (H[i] == 0) T += 0;
        else if (H[i] == 1) T += 1;
        else if (H[i] == 2) T += 2;
        else                T += 3;
        //cout << i << " " << T << endl;
    }
    cout << T << endl;
    return 0;
}
