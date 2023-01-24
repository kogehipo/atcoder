#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_m
// 解説 

#define CASE 2

#if CASE == 0
// この解答はTLEする
int main()
{
    int N, K;
    cin >> N >> K;

    int A[N];
    rep(i, 0, N) cin >> A[i];

    int ans = 0;
    rep(i, 0, N) {
        rep(j, i+1, N) {
            if ((A[j] - A[i]) <= K) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

#elif CASE == 1
// 二分探索による解
int main()
{
    int N, K;
    cin >> N >> K;

    int A[N];
    rep(i, 0, N) cin >> A[i];

    ll ans = 0;
    rep(i, 0, N-1) {
        int l = i+1;  // A[i]の次、つまり探索範囲の左端
        int r = N;    // 最後のデータ、つまり探索範囲の右端
        int idx = lower_bound(A+l, A+r, A[i]+K+1) - (A+l);
        if ((r-l+1) < idx) continue;
        //cout << i << ' ' << idx << endl;
        ans += idx;
    }
    cout << ans << endl;
    return 0;
}

#elif CASE == 2
// しゃくとり法による解
int main()
{
    int N, K;
    cin >> N >> K;

    int A[N];
    rep(i, 0, N) cin >> A[i];

    ll ans = 0;
    rep(i, 0, N) {


    }
    cout << ans << endl;
    return 0;
}
#endif