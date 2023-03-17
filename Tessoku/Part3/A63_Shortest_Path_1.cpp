#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_an
// 解説 

using Graph = vector<vector<int>>;  // グラフの型エイリアス宣言
 
int main()
{
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;
 
    // グラフを定義
    Graph G(N+1);  // N=頂点数
 
    // グラフ入力受取 (ここでは無向グラフを想定)
    for (int m=0; m<M; m++) {   // 辺の数だけループ
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);  // 有向グラフならこの行は不要
    }
 
    // BFS のためのデータ構造
    queue<int> que;
 
    // 始点からの距離。訪問フラグを兼用している。全頂点を「未訪問=-1」に初期化
    vector<int> dist(N+1, -1);
 
    // 初期条件 (頂点 1 を初期ノードとする)
    dist[1] = 0;
    que.push(1);  // BSF探索するノードのキュー（0を始点とする）
 
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
    for (int v=1; v<=N; v++) cout << dist[v] << endl;
    return 0;
}