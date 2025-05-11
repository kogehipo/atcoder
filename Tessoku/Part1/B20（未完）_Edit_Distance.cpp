#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cs
// 解説 「編集距離」「レーベンシュタイン距離」を求める問題
//      https://mathwords.net/hensyukyori
//      http://www.cs.t-kougei.ac.jp/SSys/LevenS.htm
//      http://nw.tsuda.ac.jp/lec/EditDistance/  ← 経過を記録する方法

#define INSERT_COST 1
#define DELETE_COST 1
#define CHANGE_COST 1

int main()
{
    string S, T;   // Sが元の文字列、Tがターゲット
    cin >> S >> T;

    // dp[]
    int Ssize = S.size();
    int Tsize = T.size();
    vector<vector<int>> dp(Ssize+1, vector<int>(Tsize+1));

    dp[0][0] = 0;
    range(s, 1, Ssize) dp[s][0] = s * INSERT_COST;
    range(t, 1, Tsize) dp[0][t] = t * INSERT_COST;

    range(s, 1, Ssize) {
        range(t, 1, Tsize) {
            int D = dp[s-1][t] + DELETE_COST;
            int I = dp[s][t-1] + INSERT_COST;
            int C = dp[s-1][t-1];
            if (S[s-1] != T[t-1]) C = C + CHANGE_COST;
            dp[s][t] = min({D,I,C});
        }
    }

    // debug
    cout << "--" << endl;
    cout << "X - ";
    range(t, 0, Tsize-1) cout << T[t] << ' ';
    cout << endl;
    range(s, 0, Ssize) {
        if (s == 0) cout << "- ";
        else        cout << S[s-1] << ' ';
        range(t, 0, Tsize)
            cout << dp[s][t] << ' ';
        cout << endl;
    }
    cout << "--" << endl;

    cout << dp[Ssize][Tsize] << endl;

    // バックトレースの方法
    int s = Ssize;
    int t = Tsize;
    while(dp[s][t] != 0) {
        int x = dp[s][t];
        if (dp[s-1][t-1] == x-1) {
            if      (t == 0) cout << "(" << x << ") Delete '" << S[s-1] << "'" << endl;
            else if (s == 0) cout << "(" << x << ") Insert '" << T[t-1] << "'" << endl;
            else cout << "(" << x << ") Replace '" << S[s-1] << "' with '" << T[t-1] << "'" << endl;
            s--, t--;
        }
        else if (dp[s-1][t] == x-1) {
            cout << "(" << x << ") Delete '" << S[s-1] << "'" << endl;
            s--;
        }
        else if (dp[s][t-1] == x-1) {
            cout << "(" << x << ") Insert '" << T[t-1] << "'" << endl;
            t--;
        }
        else {
            s--, t--;
        }
    }
    cout << "From " << S << " to " << T << endl;

    return 0;
}
