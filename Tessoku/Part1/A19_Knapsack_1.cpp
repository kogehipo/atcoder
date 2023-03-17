#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_s
// 解説 

int main()
{
    int N, limit;
    cin >> N >> limit;
    vector<int> W(N), V(N);
    rep(n, N) cin >> W[n] >> V[n];

    // dp配列を次のように定義する
    // 縦方向： N番目の荷物まで
    // 横方向： ありうる重さの合計。各要素は価値の合計。
    vector<vector<ll>> dp(N, vector<ll>(limit+1, 0));

    // 最初の荷物
    dp[0][W[0]] = V[0];

    // 2つめ以降の荷物（この部分、模範解答とロジックが異なる）
    range(n, 1, N-1) {
        if (dp[n][W[n]] < V[n]) dp[n][W[n]] = V[n];  // n番目の荷物だけ使う場合
        range(w, 0, limit) {  // これまでの荷物との組み合わせで使う場合
            if (dp[n-1][w]) {
                if (dp[n][w] < dp[n-1][w])
                    dp[n][w] = dp[n-1][w];  // n番目の荷物を使わない場合
                if (w+W[n] <= limit && dp[n][w+W[n]] < dp[n-1][w] + V[n])
                    dp[n][w+W[n]] = dp[n-1][w] + V[n];  // n番目の荷物を使う場合
            }
        }
    }

/*
    rep(i, N) {
        rep(j, limit+1) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
*/
    auto it = max_element(dp[N-1].begin(), dp[N-1].end());
    cout << *it << endl;
    return 0;
}
