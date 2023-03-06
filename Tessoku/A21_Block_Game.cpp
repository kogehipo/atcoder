#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_u
// 解説 

int N;
vector<int> P, A;

int updateDP(vector<vector<int>>& dp, int l, int r)  // dpは参照渡し
{
    if (dp[l][r] != -1) return dp[l][r]; // dp既に計算済み

    // 左側(l-1)を取って現状にたどり着いた時（その時の得点=x）
    int x;
    if (l <= 1) {
        x = 0;
    } else {
        x = updateDP(dp, l-1, r);
        if (l <= P[l-1] && P[l-1] <= r) x += A[l-1];
    }

    // 右側(r+1)を取って現状にたどり着いた時（その時の得点=y）
    int y;
    if (N <= r) {
        y = 0;
    } else {
        y = updateDP(dp, l, r+1);
        if (l <= P[r+1] && P[r+1] <= r) y += A[r+1];
    }

    // x,yの大き良いほうが求めるdp
    int z = max(x, y);
    dp[l][r] = z;  // dpテーブルを更新
    return z;
}

int main()
{
    cin >> N;
    P.push_back(0);
    A.push_back(0);
    range(n, 1, N) {
        int x;
        cin >> x; P.push_back(x);
        cin >> x; A.push_back(x);
    }

    // 残ったブロック列にたいしてdpを次のように定義する。
    // dp[左端ブロック番号][右端ブロック番号]、
    // 値は得られる得点の最大値（初期値は-1）
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
    dp[1][N] = 0;
    range(l, 1, N) range(r, 1, N) updateDP(dp, l, r);

    int ans = -1;
    range(l, 1, N) range(r, 1, N) ans = max(ans, dp[l][r]);
    cout << ans << endl;
    return 0;
}
