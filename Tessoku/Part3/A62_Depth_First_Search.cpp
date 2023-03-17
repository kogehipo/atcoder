#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_am
// 解説 

using Graph = vector<vector<int>>;  // グラフの型エイリアス宣言
vector<bool> visited;  // 訪問済フラグ
 
// 深さ優先探索
void dfs(const Graph &G, int v)
{
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
    Graph G(N+1);  // N=頂点数
 
    // グラフ入力受取 (ここでは無向グラフを想定)
    for (int m=0; m<M; m++) {   // 辺の数だけループ
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);  // 無向グラフなので双方向を登録
        G[b].push_back(a);  // 有向グラフならこの行は不要
    }

    // 頂点訪問したフラブ（サイズNをfalseで初期化）
    visited.assign(N+1, false);
 
    // 頂点 1 をスタートとした探索
    dfs(G, 1);

    range (i, 1, N) {
        //cout << i << ' ' << visited[i] << endl;
        if (!visited[i]) {
            cout << "The graph is not connected." << endl;
            return 0;
        }
    }
    cout << "The graph is connected." << endl;
    return 0;
}