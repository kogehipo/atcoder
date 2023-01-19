#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_g
// 解説 

#define CASE 0

#if CASE == 0
int main()
{
    int D, N;
    cin >> D >> N;  // D日間、N人が参加
    int L[N+2], R[N+2];
    rep(i, 0, N) cin >> L[i] >> R[i];

    // 人員の増減をリストする
    int ans[D+2] = {0};
    rep(i, 0, N) {
        ans[L[i]  ]++;   // L日目から参加
        ans[R[i]+1]--; // R日目まで参加（翌日は来ない）
    }

/*
    rep(i, 0, D) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
*/

    // 増減リストから累積和を作る
    rep(i, 1, D+1) {
        if (0<i) {
            ans[i] = ans[i-1] + ans[i];
        }
        cout << ans[i] << endl;
    }

    return 0;
}
#endif

#if CASE == 1
// パスするが時間がかかる。本番問題ならTLEの可能性。
int main()
{
    int D, N;
    cin >> D >> N;
    int L[N], R[N];
    rep(i, 0, N) cin >> L[i] >> R[i];

    int ans[D] = {0};
    for (int i=0; i<N; i++) {
        for (int j=L[i]-1; j<=R[i]-1; j++) {
            ans[j]++;
        }
    }

    rep(i, 0, D) {
        cout << ans[i] << endl;
    }

    return 0;
}
#endif
