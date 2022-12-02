// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=ja
// 解説 考え方がよく分かる
// https://o-treetree.hatenablog.com/entry/DPL1A

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define INF 100000  // 無限大：初期値として十分大きな数


#if 0
// 二次元のDPテーブルを使う場合
int main()
{
    // M種類のコインを使って、Pay円(=N)を支払う。
    int Pay, M;
    cin >> Pay >> M;

    // M種類のコインの額面（便宜上、0円も入れる）
    int c[M+1];
    c[0] = 0;
    for (int m=1; m<=M; m++) cin >> c[m];
    sort(c, c+M);  // いちおう昇順に並べ替えておく（問題文に前提が書いてないので）

    // DPテーブルを定義（便宜上、額面0円のコイン、0円の支払いも含める）
    // M番目までのコインを使って、Pay円を支払うときの最小枚数  
    int dp[M+1][Pay+1];

    // コインを使わないでp円払うのは不可能
    for (int p=1; p<=Pay; p++) {
        dp[0][p] = INF;
    }

    // コインの使い方によらず0円払うのは0枚
    for (int m=0; m<=M; m++) {
        dp[m][0] = 0;
    }

    // DPテーブルを埋める
    for (int m=1; m<=M; m++) {        // 1番目からm番目のコインを使って、
        for (int p=1; p<=Pay; p++) {  // 1円からp円を支払う。
            // 支払額がm番目のコイン額面より小さい場合、そのコイン種は使えない。
            // 従って、支払い方はm-1番目のコイン額面までの時と変わらず。
            if (p < c[m]) {
                dp[m][p] = dp[m-1][p];
            }
            // 支払額がm番目のコイン額面以上の場合、そのコインが使える可能性がある。
            else {
                // 使わなければ、支払い方はm-1番目のコイン額面までの時と変わらず。
                int decision1 = dp[m-1][p];
                // それを1枚使うなら、残りの支払額p-c[m]の枚数＋1枚
                int decision2 = dp[m][p-c[m]]+1;
                // どちらか小さい方
                dp[m][p] = min(decision1, decision2);
            }
        }
    }

    int ans = dp[M][Pay]; // M番目までのコインを使ってPay円払う最小枚数
    cout << ans << endl;
    return 0;
}
#endif


#if 1
// 一次元のDPテーブルを使う場合
int main()
{
    // M種類のコインを使って、Pay円(=N)を支払う。
    int Pay, M;
    cin >> Pay >> M;

    // M種類のコインの額面（便宜上、0円も入れる）
    int c[M+1];
    c[0] = 0;
    for (int m=1; m<=M; m++) cin >> c[m];
    sort(c, c+M);  // いちおう昇順に並べ替えておく（問題文に前提が書いてないので）

    // DPテーブルを定義（便宜上、0円の支払いも含める）
    // Pay円を支払うときの最小枚数  
    int dp[Pay+1];

    // 初期値=無限大の枚数だけ必要
    for (int p=0; p<=Pay; p++) dp[p] = INF;

    // 0円払うのは1枚
    dp[0] = 0;

    // DPテーブルを埋める
    for (int m=1; m<=M; m++) {        // 1番目からm番目のコインを使って、
        for (int p=1; p<=Pay; p++) {  // 1円からp円を支払う。
            // 支払額がm番目のコイン額面より小さい場合、そのコイン種は使えない。
            // 従って、支払い方はm-1番目のコイン額面までの時と変わらず。
            if (p < c[m]) {
/*
            DPテーブルを一次元にしたのでこの部分は何もしなくて良い。
                dp[m][p] = dp[m-1][p];
*/
                ;  // 何もしない
            }
            // 支払額がm番目のコイン額面以上の場合、そのコインが使える可能性がある。
            else {
                // 使わなければ、支払い方はm-1番目のコイン額面までの時と変わらず。
                int decision1 = dp[p];
                // それを1枚使うなら、残りの支払額p-c[m]の枚数＋1枚
                int decision2 = dp[p-c[m]]+1;
                // どちらか小さい方
                dp[p] = min(decision1, decision2);
            }
        }
    }

    int ans = dp[Pay]; // M番目までのコインを使ってPay円払う最小枚数
    cout << ans << endl;
    return 0;
}
#endif