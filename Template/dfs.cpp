// 問題 DFS(深さ優先探索)のテンプレート
// 解説 前編 https://qiita.com/drken/items/4a7869c5e304883f539b
//     後編 https://qiita.com/drken/items/a803d4fc4a727e02f7ba

// 入力データ形式
// N M    Nは頂点数、Mは辺数
// a[0] b[0]
// a[1] b[1]
//  ...
// a[M-1] b[M-1]

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

using Graph = vector<vector<int>>;  // グラフの型エイリアス宣言
vector<bool> visited;  // 訪問済フラグ

// 深さ優先探索
void dfs(const Graph &G, int v) {

    // 訪問済みなら再帰コールしないようにしているのでこの行は不要
    // ただし、設問の不備によりこの行が必要なこともある（ALDS1_11_B）
    if (visited[v]) return; // 訪問済みなら何もせず返る

    // 行きがけ処理はここに書く

    visited[v] = true; // vを訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (visited[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }

    // 帰りがけ処理はここに書く
}

int main()
{
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフを定義
    Graph G(N);

    // グラフ入力受取 (ここでは無向グラフを想定)
    rep(m, 0, M) {   // 辺の数だけループ
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);  // 無向グラフなので双方向を登録
        G[b].push_back(a);  // 有向グラフならこの行は不要
    }

/*
    // グラフをダンプ（DEBUG用）
    rep(n, 0, N) {   // 辺の数だけループ
        for (auto v : G[n]) {
            cout << n << ' ' << v << endl;
        }
    }
*/

    // 頂点訪問したフラブ（サイズNをfalseで初期化）
    visited.assign(N, false);

    // 頂点 0 をスタートとした探索
    dfs(G, 0);
}
