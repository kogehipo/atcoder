#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/dp_a
// 解説 

int main()
{
    int N; cin >> N;
    vector<int> H(N+1); range(i, 1, N) cin >> H[i];

    // dp[i]は、H[i]に辿り着くまでの最小コスト
    vector<int> dp(N+1);
    dp[1] = 0;
    dp[2] = abs(H[1]-H[2]);
    range(i, 3, N)
        dp[i] = min(dp[i-1]+abs(H[i]-H[i-1]), dp[i-2]+abs(H[i]-H[i-2]));

    cout << dp[N] <<  endl;
    return 0;
}
