#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cr
// 解説 A19と問題は同じだが制約が異なる。

int main()
{
    int N, weight_limit;
    cin >> N >> weight_limit;
    vector<int> W(N), V(N);
    rep(n, N) cin >> W[n] >> V[n];

    // dp配列を次のように定義する
    // 縦方向： N番目の荷物まで
    // 横方向： ありうる価値の合計。各要素は重さの合計。（A19とは重さと価値が逆）
    vector<vector<ll>> dp(N, vector<ll>(1000*N+1, INF)); // 初期値は重さが無限大

    // 最初の荷物（価値V[0]の重さはW[0]）
    dp[0][V[0]] = W[0];

    // 2つめ以降の荷物
    range(n, 1, N-1) {
        // 価値V[n]を、n番目の荷物ひとつで、より軽く実現できる場合
        if (W[n] < dp[n][V[n]]) dp[n][V[n]] = W[n];  // n番目の荷物だけ使う

        range(v, 0, 1000*N) {  // これまでの荷物との組み合わせで使う場合
            if (dp[n-1][v]) {
                // n番目の荷物を使わない場合は、これまでのDP表の重さを引き継ぐ
                if (dp[n-1][v] < dp[n][v]) dp[n][v] = dp[n-1][v];

                // n番目の荷物を使う場合は重さがW[n]だけ増える
                if (dp[n-1][v]+W[n] < dp[n][v+V[n]] && dp[n-1][v]+W[n] <= weight_limit)
                    dp[n][v+V[n]] = dp[n-1][v] + W[n];  // n番目の荷物を使う場合
            }
        }
    }

    for (int v=1000*N; 0<=v; v--) {
        for (int n=0; n<N; n++) {
            if (dp[n][v] != INF) {
                cout << v << endl;
                return 0;
            }
        }
    }
}
