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
    ll N,S; cin >>N>>S;
    ll cycleSum = 0; // 1周期の合計
    vector<int> A(N*2);  // 2周期分のデータを持つ
    rep(i,N) {
        cin >>A[i];
        A[N+i] = A[i];
        cycleSum += A[i];
    }
    S = S % cycleSum;  // 周期をまたぐ分を削除

    //cout << "S=" << S << endl;
    //rep(i,N*2) cout << A[i] << " ";
    //cout << endl;

    // 尺取法 - l=r=0から開始
    int r = 0;
    ll sum = A[0];
    range(l,0,N*2-1) {
        if (sum < S) {
            while (r < N*2-1 && sum < S) {
                r++;
                sum += A[r];
            }
        }
        if (sum == S) {
            cout << "Yes" << endl;
            return 0;
        }
        else if (sum > S) {
            sum -= A[l];
        }
    }
    cout << "No" << endl;
    return 0;
}
