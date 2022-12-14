// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B&lang=ja
// 解説 これは構造体と再帰をつかう方法。

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


struct nodetype {
    int U;      // ノード番号
    int K;      // 接続されたノード数
    int V[110]; // 接続されたノード
    int D;      // 最初に訪れた時刻
    int F;      // 最後に訪れた時刻
};
nodetype node[110];  // Global変数なので0に初期化される
int Time;

void search(int n)
{
    if (0 < node[n].D) return;  // 既に訪問済みならなにもしない
    node[n].D = ++Time;         // 訪問時刻を記録
    rep(k, 0, node[n].K)        // 接続リストを順に訪問
        search(node[n].V[k]);
    node[n].F = ++Time;         // 完了時刻を記録
}

int main()
{
    // ノード数
    int N;
    cin >> N;

    // 全データ入力
    rep(n, 1, N+1) {
        cin >> node[n].U >> node[n].K;
        rep(k, 0, node[n].K) cin >> node[n].V[k];
    }

    // 時刻を初期化
    Time = 0;

    // 全ノードを順に調べる
    rep(n, 1, N+1) search(node[n].U);

    // 出力
    rep(n, 1, N+1) {
        cout << node[n].U << ' '
             << node[n].D << ' '
             << node[n].F << endl;
    }

    return 0;
}
