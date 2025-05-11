#include <bits/stdc++.h>
using namespace std;
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cq
// 解説 

int main()
{
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    rep(n, N) cin >> A[n];

    // 横軸: 0〜Sまで
    // 縦軸: 0〜N-1まで
    // の2次元配列のdpを持つ。
    // 各要素は、N枚目までのカードを使って、Sを作れるかどうかをT/Fで示す。
    vector<vector<bool>> dp(N, vector<bool>(S+1, false));

    // 1枚目
    dp[0][A[0]] = true;

    // 2枚目以降
    range(n, 1, N-1) {
        if (A[n] <= S) dp[n][A[n]] = true;  // n番目のカードだけ使う場合
        range(s, 0, S) {  // これまでのカードとの組み合わせで使う場合
            if (dp[n-1][s]) {
                dp[n][s] = true;  // n番目のカードを使わない場合
                if (s+A[n] <= S) dp[n][s+A[n]] = true;  // n番目のカードを使う場合
            }
        }
    }
/*
    // Debug
    cout << "--" << endl;
    rep(n, N) {
        rep(s, S+1) {
            cout << dp[n][s] << ' ';
        }
        cout << endl;
    }
    cout << "--" << endl;
*/

    if (!dp[N-1][S]) {
        cout << "-1" << endl;
        return 0;
    }

    stack<int> ans;
    int K = 0;
    int sum = S;
    int n = N-1;
    while (0<sum) {
        if (n==0 || !dp[n-1][sum]) {
            sum -= A[n];
            ans.push(n+1);
            K++;
        }
        n--;
    }
    cout << K << endl;
    while (!ans.empty()) {
        cout << ans.top(); ans.pop();
        if (--K) cout << ' ';
    }
    cout << endl;
    return 0;
}
