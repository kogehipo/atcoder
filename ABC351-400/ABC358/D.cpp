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
    int N,M; cin >>N>>M;
    vector<int> A(N); rep(i,N) cin >>A[i];
    vector<int> B(M); rep(i,M) cin >>B[i];
    sort(all(A));
    sort(all(B));
    ll ans = 0;
    int a = 0;
    rep(b,M) {
        while(A[a] < B[b]) {
            a++;
            if (N <= a) {
                cout << -1 << endl;
                return 0;
            }
        }
        // Aの最後の要素を使った次の回で、Aの範囲を
        // 超えてしまう場合があるので、ここで再チェック
        //cout << "a= " << a << " A[a]= " << A[a] << endl;
        if (N <= a) {
            cout << -1 << endl;
            return 0;
        }
        ans += A[a];
        //cout << "selected=" << A[a] << " for " << B[b] << endl;
        a++;
    }
    cout << ans << endl;
    return 0;
}
