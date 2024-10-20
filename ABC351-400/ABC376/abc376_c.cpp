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

// 要素数3以上のmin/max（C++20から）
#define min std::ranges::min
#define max std::ranges::max

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
    vector<int> A(N); rep(i,N) cin >>A[i];
    vector<int> B(N-1); rep(i,N-1) cin >>B[i];
    sort(rall(A));
    sort(rall(B));
    int ans = -1;
    int a = 0;
    int b = 0;
    while(a<N) {
        if (A[a] <= B[b]) {  // 箱に入る
            a++; b++;
        } else if (ans != -1) {
            if (A[a] > B[b]) {
                cout << -1 << endl;
                return 0;
            }
            a++; b++;
        } else {  // 箱に入らないので買う
            ans = A[b];
            a++;
        }
    }
    cout << ans << endl;
    return 0;
}
