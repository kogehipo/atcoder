#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_j
// 解説 

#define CASE 1

#if CASE == 0
// これはTLEになる
int main()
{
    int N;
    cin >> N;

    vector<int> A = {0};
    rep(n, 0, N) { int a; cin >> a; A.push_back(a); }

    int D;
    cin >> D;

    vector<int> L, R;
    rep(d, 0, D) {
        int l, r;
        cin >> l >> r;
        L.push_back(l);
        R.push_back(r);
    }

    rep(d, 0, D) {
        int ans = 0;
        rep(n, 0, N) {
            if (L[d]<=n && n<=R[d]) continue;
            ans = max(ans, A[n]);
        }
        cout << ans << endl;
    }

    return 0;
}
#endif

#if CASE == 1
int main()
{
    // 入力
    int N;
    cin >> N;

    int A[N+2];
    A[0] = 0;
    for (int n=1; n<=N; n++) cin >> A[n];
    A[N+1] = 0;

    int D;
    cin >> D;

    vector<int> L, R;
    rep(d, 0, D) {
        int l, r;
        cin >> l >> r;
        L.push_back(l);
        R.push_back(r);
    }

    // 累積最大値（左から）
    int M1[N+2];
    M1[0] = M1[N+1] = 0;
    for (int n=1; n<=N; n++) M1[n] = max(M1[n-1], A[n]);

    // 累積最大値（右から）
    int M2[N+2];
    M2[0] = M2[N+1] = 0;
    for (int n=N; 1<=n; n--) M2[n] = max(M2[n+1], A[n]);

    // L,Rを挟んで左側の最大値と右側の最大値の大きい方
    rep(d, 0, D) {
        cout << max(M1[L[d]-1], M2[R[d]+1]) << endl;
    }

    return 0;
}
#endif
