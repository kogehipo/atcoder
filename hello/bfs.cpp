// 問題 BSF(幅優先探索)のテンプレート
// 解説 https://qiita.com/drken/items/996d80bcae64649a6580

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
        G[a].push_back(b);
        G[b].push_back(a);  // 有向グラフならこの行は不要
    }

    // BFS のためのデータ構造
    queue<int> que;

    // 始点からの距離。訪問フラグを兼用している。全頂点を「未訪問=-1」に初期化
    vector<int> dist(N, -1);

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0);  // BSF探索するノードのキュー（0を始点とする）

    // BFS開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから探索すべき頂点を取り出す
        que.pop();  // キューから削除

        // v から辿れる頂点をすべて調べる
        for (int next : G[v]) {
            if (dist[next] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点nextの距離は1だけ大きい
            dist[next] = dist[v] + 1;
            // 後で探索するのでキューに追加する
            que.push(next);
        }
    }

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    rep(v, 0, N) cout << v << ": " << dist[v] << endl;
}
