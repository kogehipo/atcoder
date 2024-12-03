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
    int N,K; cin >>N>>K;
    vector<int> A(N); rep(i,N) cin >>A[i];
    sort(all(A));
    vector<int> B(N);
    B[0] = A[0];
    range(i,1,N-1) B[i] += B[i-1] + A[i];

    //rep(i,N) cout << B[i] << " ";
    //cout << endl; 

    ll sum = 0;
    ll idxL = 0, idxR = N-1;
    range(l, 0, K) {
        int r = K - l;
        ll L = A[l] - A[0];
        ll R = A[N-1] - A[N-r-1];
        if (sum < L+R) {
            sum = L+R;
            idxL = l;
            idxR = N-r-1;
        }
    }

    cout << A[idxR] - A[idxL] << endl;
    return 0;
}