#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

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
    rep(i, N) cin >> A[i];

    int ans = 0;
    rep(i, N) {
        range(j, i+1, N-1) {
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
    rep(i, N) cin >> A[i];

    ll ans = 0;
    range(i, 0, N-2) {
        int l = i+1;  // 左端はA[i+1]
        int size = N-(i+1);  // 右端はA[N-1]
        int idx = lower_bound((A+l), (A+l)+size, A[i]+K+1) - (A+l);
        if (size <= idx) ans += size;
        else             ans += idx;
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
    rep(i, N) cin >> A[i];

    ll ans = 0;
    int j = 0;   // しゃくとりの先頭インデックス
    range(i, 0, N-2) {
        ans += j - i;  // 前回のしゃくとり位置までは計算しなくても条件を満足する
        while (j+1 <= N-1   // しゃくとりの先頭をデータ末尾まで、 
               && A[j+1] - A[i] <= K) {  // かつ差がK以下の範囲で伸ばす
            j++;
            ans++;
        }
        //cout << i << ' ' << j << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
#endif
