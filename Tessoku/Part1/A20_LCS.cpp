#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_t
// 解説 

int main()
{
    string S, T;
    cin >> S >> T;
    int sLen = S.size();
    int tLen = T.size();

    // dp定義
    // 文字列S,Tの各長さ+1の２次元平面
    // 要素の値は、その場所までの最大の部分文字数
    vector<vector<int>> dp(sLen+1, vector<int>(tLen+1, -1));

    dp[0][0] = 0;
    range(s, 0, sLen) {
        range(t, 0, tLen) {
            if (s == 0 || t == 0) { dp[s][t] = 0; continue; }
            dp[s][t] = max(dp[s-1][t], dp[s][t-1]);
            if (S[s-1] == T[t-1]) dp[s][t] = max(dp[s][t], dp[s-1][t-1]+1);
        }
    }
/*
    // Debug
    range(s, 0, sLen) {
        range(t, 0, tLen) {
            cout << dp[s][t] << ' ';
        }
        cout << endl;
    }
*/
    cout << dp[sLen][tLen] << endl;
    return 0;
}
