#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_v
// 解説 

int main()
{
    int N;
    cin >> N;
    vector<int> A(N+9), B(N+9);
    range(n, 1, N-1) cin >> A[n];
    range(n, 1, N-1) cin >> B[n];

    vector<int> dp(N+9, -200);  // +150した値と比較するので初期値は小さく
    dp[1] = 0;
    range(n, 1, N-1) {
        dp[A[n]] = max(dp[A[n]], dp[n]+100);
        dp[B[n]] = max(dp[B[n]], dp[n]+150);
    }
    cout << dp[N] << endl;
    return 0;
}
