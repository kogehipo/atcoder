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
    int N, X;
    cin >> N >> X;
    N--;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));
    int min = A[0];
    int max = A[N-1];
    int sum = 0;
    range(i, 1, N-2) sum += A[i];
    int ans = 0;
    if (X <= sum) {
        ans = 0;
    } else if (sum + max < X) {
        ans = -1;
    } else {
        ans = X - sum;
        if      (ans <= min) ans = 0;
        else if (100 < ans) ans = -1; 
    }
    cout << ans << endl;
    return 0;
}
