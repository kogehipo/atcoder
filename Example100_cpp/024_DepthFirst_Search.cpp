// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B&lang=ja
// 解説 テンプレを使用
//     ・この問題は有向グラフで有ることに注意
//     ・他にも問題文に冗長な部分あり

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

using Graph = vector<vector<int>>;  // グラフの型エイリアス宣言
vector<bool> visited;  // 訪問済フラグ

int Time;  // 時刻
vector<int> time_visited;  // 訪問時刻
vector<int> time_left;     // 退去時刻

// 深さ優先探索
void dfs(const Graph &G, int v) {

    if (visited[v]) return; // 訪問炭なら何もせず帰る

    // 行きがけ処理はここに書く
    time_visited[v] = ++Time;

    visited[v] = true; // vを訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (visited[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }

    // 帰りがけ処理はここに書く
    time_left[v] = ++Time;
}

int main()
{
    // 頂点数と辺数
    int N;
    cin >> N;

    // グラフを定義
    Graph G(N+1);  // 1始まりにしたいので大きさを+1

    // グラフ入力受取 (ここでは無向グラフを想定)
    rep(n, 1, N+1) {   // 頂点の数だけループ(1始まり)
        int u, K;
        cin >> u >> K;
        rep(k, 0, K) {
            int a;
            cin >> a;
            G[u].push_back(a);  // 無向グラフなので双方向を登録
            //G[a].push_back(u);  // 有向グラフならこの行は不要
        }
    }

    // 頂点訪問したフラブ（サイズNをfalseで初期化）
    visited.assign(N+1, false);

    Time = 0;  // 時刻
    time_visited.assign(N+1, -1);  // 訪問時刻
    time_left.assign(N+1, -1);     // 退去時刻

    // 頂点 0 をスタートとした探索
    //dfs(G, 1);    // これで正しいが、連結されてない頂点も探索しないと正答にならない（問題文が間違っている）
    rep(n, 1, N+1) dfs(G, n);

    // 出力
    rep(n, 1, N+1) {
        cout << n << ' ' << time_visited[n] << ' ' << time_left[n] << endl;
    }
}
