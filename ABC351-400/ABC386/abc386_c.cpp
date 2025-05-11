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
    int K; cin >>K;
    string S,T; cin >>S>>T;
    int lenS = S.size();
    int lenT = T.size();

    if (lenS == lenT-1) {
        int s = 0;
        rep(t,lenT) {
            if (T[t] != S[s]) {
                if (s == t) continue;
                else {
                    cout << "No" << endl;
                    return 0;
                }
            }
            s++;
        }
        cout << "Yes" << endl;
        return 0;
    }
    else if (lenT == lenS-1) {
        swap(S,T);
        int s = 0;
        rep(t,lenT) {
            if (T[t] != S[s]) {
                if (s == t) continue;
                else {
                    cout << "No" << endl;
                    return 0;
                }
            }
            s++;
        }
        cout << "Yes" << endl;
        return 0;
    }
    else if (lenT == lenS) {
        int cnt = 0;
        int s = 0;
        rep(t,lenT) {
            if (T[t] != S[s]) cnt++;
            s++;
        }
        if (cnt <= 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
