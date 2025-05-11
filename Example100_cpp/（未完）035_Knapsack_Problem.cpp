// 動的計画法の典型問題
// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=ja
// 解説 http://dai1741.github.io/maximum-algo-2012/docs/dynamic-programming/
//     https://o-treetree.hatenablog.com/entry/DPL1B

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


#if 0
// ここから下は再帰関数を使った実装。これは時間オーバーになる。

// N: 品物の数
// W: ナップザックの容量
// v[100]: 品物nの価値
// w[100]: 品物nの重さ(容量)
int N, W, v[110], w[110];   // 配列は少し多めに確保

// n番目以降の荷物について、残り容量capaに詰め込める最大価値を求める。
// n    : 調べる品物の番号（n番目以降を調べる）
// capa : 残りの容量（キャパ）
// 戻り値: n番目以降で、取りうる最大の価値
int get_max_value(int n, int capa)
{
    // 品物が残ってなければ何も持てない。N番目以降の価値の総和は0。
    if (n == N) return 0;

    // n番目の品物に注目して、それがキャパオーバーなら持てない。
    // n+1番目以降の最大価値を、n番目以降の最大価値とする。
    if (capa < w[n]) return get_max_value(n+1, capa);

    // ここ以降、n番目の荷物を持つか持たないかで判断が分かれる。

    // n番目の品物を持たないと判断した場合、価値は増えない。
    // n+1番目以降の最大価値が、n番目以降の最大価値となる。
    int decision1 = get_max_value(n+1, capa);

    // n番目の品物を持つと判断した場合は、キャパは減って、価値は増える。
    int decision2 = get_max_value(n+1, capa-w[n]) + v[n];

    // どちらか価値の大きい方が取りうる最大価値。
    return max(decision1, decision2);
}

int main()
{
    // 入力
    cin >> N >> W;
    rep (n, N) cin >> v[n] >> w[n];

    // ナップサックの容量Wをキャパとして、最初の荷物以降の最大価値を求める。
    cout << get_max_value(0, W) << endl;

    return 0;
}
#endif


#if 0
// ここから下は再帰関数を使った実装。
// 高速化のために途中結果を記録する（メモ化）。これはパスする。

// N: 品物の数
// W: ナップザックの容量
// v[100]: 品物nの価値
// w[100]: 品物nの重さ
int N, W, v[110], w[110];   // 配列は少し多めに確保

// n番目以降の荷物について、残り容量capaに詰め込める最大価値を求める。
// n    : 調べる品物の番号（n番目以降を調べる）
// capa : 残りの容量（キャパ）
// 戻り値: n番目以降で、取りうる最大の価値
// この関数はn,capaが同じなら同じ結果になる。
// 既に計算済みだったらその値をdp[][]に覚える。
int dp[110][10010];
int get_max_value(int n, int capa)
{
    int ret;

    // 既に調べたことのある組み合わせだったらその値を返す。
    if (0 <= dp[n][capa]) {
        return dp[n][capa];
    }

    // 品物が残ってなければ何も持てない。N番目以降の価値の総和は0。
    if (n == N) {
        ret = 0;
    }

    // n番目の品物に注目して、それが大き過ぎたら持てない。
    // n+1番目以降の最大価値を、n番目以降の最大価値とする。
    else if (capa < w[n]) {
        ret = get_max_value(n+1, capa);
    }

    // ここで、n番目の荷物を持つか持たないかの判断が必要。
    else {
        // n番目の品物を持たない判断した場合、価値は増えない。
        // n+1番目以降の最大価値が、n番目以降の最大価値となる。
        int decision1 = get_max_value(n+1, capa);

        // n番目の品物を持つと判断した場合は、キャパは減って、価値は増える。
        int decision2 = get_max_value(n+1, capa-w[n]) + v[n];

        // どちらか価値の大きい方になる。
        ret = max(decision1, decision2);
    }

    // メモしてリターン
    dp[n][capa] = ret;
    return ret;
}

int main()
{
    // 入力
    cin >> N >> W;
    rep (n, N) {
        cin >> v[n] >> w[n];
    }

    memset(dp, -1, sizeof(dp));

    // ナップサックの容量Wを、荷物を持つキャパとして、最初の荷物から調べる。
    cout << get_max_value(0, W) << endl;

    return 0;
}
#endif


#if 0
// 再帰を用いた方法を考察すると、
// nが大きく、capaが小さい順（荷物と容量が少ない順）に値が決まる。
// これは漸化式で表現できる。
int main()
{
    // N: 品物の数
    // W: ナップザックの容量
    // v[100]: 品物nの価値
    // w[100]: 品物nの重さ
    int N, W, v[110], w[110];   // 配列は少し多めに確保

    // DPテーブル
    // n番目以降の商品について、残容量capaの場合の、
    // 商品の最大価値は一意に決まる。これをdp[n][capa]に記録する。
    int dp[110][10010];

    // 入力
    cin >> N >> W;
    rep (n, N) cin >> v[n] >> w[n];

    // 商品番号は0〜N-1。残り商品が無ければ(N番目)残容量に関わらず価値は0
    rep (capa, W) dp[N][capa] = 0;

    // n（品物の番号）を大きい方からループ
    for (int n=N-1; 0<=n; n--) {
        // capa（残り容量）を小さい順にループ
        for (int capa=0; capa<=W; capa++) {
            // n番目の品物に注目して、それが大き過ぎたら持てない。
            // n+1番目以降の最大価値を、n番目以降の最大価値とする。
            if (capa < w[n]) {
                dp[n][capa] = dp[n+1][capa];
            }
            else {
                // n番目の品物を持たない判断した場合、価値は増えない。
                // n+1番目以降の最大価値が、n番目以降の最大価値となる。
                int decision1 = dp[n+1][capa];
                // n番目の品物を持つと判断した場合は、キャパは減って、価値は増える。
                int decision2 = dp[n+1][capa-w[n]] + v[n];
                // どちらか価値の大きい方になる。
                dp[n][capa] = max(decision1, decision2);
            }
        }
    }

    cout << dp[0][W] << endl;
    return 0;
}
#endif


#if 1
// 前の回答はループの向きが逆順になっているので、順方向のループに書き換える。
int main()
{
    // N: 品物の数
    // W: ナップザックの容量
    // v[100]: 品物nの価値
    // w[100]: 品物nの重さ
    int N, W, v[110], w[110];   // 配列は少し多めに確保

    // DPテーブル
    // n番目「まで」の商品について、残容量capaの場合の、
    // 商品の最大価値は一意に決まる。これをdp[n][capa]に記録する。
    int dp[110][10010];

    // 入力
    cin >> N >> W;
    rep (n, N) cin >> v[n] >> w[n];

    // 商品を何も持っていなければ(n=0)残容量に関わらず価値は0
    rep (capa, W) dp[0][capa] = 0;

    // n+1番目(1〜N)までの荷物について考える
    for (int n=0; n<N; n++) {
        // capa（残り容量）を小さい順にループ
        for (int capa=0; capa<=W; capa++) {
            // n+1番目までの最大価値は、n番目までの最大価値に等しい。
            if (capa < w[n]) {
                dp[n+1][capa] = dp[n][capa];
            }
            else {
                // n+1番目の品物を持たないと判断した場合、価値は増えない。
                // n+1番目までの最大価値は、n番目までの最大価値に等しい。
                int decision1 = dp[n][capa];
                // n+1番目の品物を持つと判断した場合は、キャパは減って、価値は増える。
                int decision2 = dp[n][capa-w[n]] + v[n];
                // どちらか価値の大きい方になる。
                dp[n+1][capa] = max(decision1, decision2);
            }
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}
#endif
