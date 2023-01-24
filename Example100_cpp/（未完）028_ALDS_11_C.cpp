// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja
// 解説 https://algorithmbeginner.blogspot.com/2019/08/alds111c.html
//     https://algorithmbeginner.blogspot.com/2019/08/alds111c_27.html

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

#define DEBUG
#define MAX_NODE 110

struct nodetype {
    int U;           // ノード番号（添字=ノード番号にしている）
    int K;           // 接続されたノード数
    int V[MAX_NODE]; // 接続されたノード番号のリスト
    int visited;     // 訪問済みフラグ
    int D;           // ノード1からの距離
};
nodetype node[MAX_NODE];  // Global変数なので0に初期化される

// 総ノード数
int N;

#ifdef DEBUG
void dump()
{
    rep(n, 1, N+1) {
        cout << "No:" << node[n].U << " D=" <<  node[n].D << " branch=";
        rep(k, 0, node[n].K) cout << " " << node[n].V[k];
        cout << endl;
    }
    cout << "----" << endl;
}
#endif

void bfs(int n)  // n = 頂点番号
{
#ifdef DEBUG
    cout << "n:" << n << endl;
    dump();
#endif

    if (node[n].visited == 1) return; // 訪問済みなら何もしない
    node[n].visited == 1;  // 訪問済をマーク
    int distance = node[n].D + 1; // これから探索するノードの距離は+1


if (10 < distance) exit(0);

    queue<int> qu;

    // 今のノードが指しているノードを探す
    rep(k, 0, node[n].K) {         // 分岐しているノード数
        int child = node[n].V[k];  // 分岐先のノードの番号
        if (node[child].visited == 1) continue;  // 訪問済み
        qu.push(node[child].U);     // このノードは後で探索する

        cout << node[child].U << " was pushed (1)" << endl;

    }

    // 今のノードが指されているノードを探す
    rep(m, 1, N+1) {     // 全ノードを調べる
        if (n == m) continue;  // 自分自身なら何もしない
        if (node[m].visited == 1) continue;  // 訪問済みなら何もしない
        rep(k, 0, node[m].K) {
            int child = node[m].V[k];  // 分岐先のノードの番号
            if (n != child) continue;  // 自分を指してなければ何もしない
            qu.push(node[m].U);     // このノードは後で探索する

            cout << node[m].U << " was pushed (2)" << endl;

        }
    }

    while(!qu.empty()) {        // 探索が必要なノード
        int child = qu.front();   // 探索するノード番号

        cout << "Go next to: " << child << endl;

        node[child].D = distance;  // このノードの距離を設定
        bfs(node[child].U);   // BFS
        qu.pop();
    }

}

int main()
{
    // グラフ領域すべて-1で初期化（未探索なら-1としたいので）
    memset(node, -1, sizeof(node));

    // ノード数
    cin >> N;

    // 全データ入力
    rep(n, 1, N+1) {
        cin >> node[n].U >> node[n].K;
        rep(k, 0, node[n].K) cin >> node[n].V[k];
    }

#ifdef DEBUG
    cout << "---- Initial data ----" << endl;
    dump();
#endif

    // ノード1から調べる
    node[1].D = 0;  // ノード1の距離は０
    bfs(node[1].U);

    // 出力
    rep(n, 1, N+1) {
        cout << node[n].U << ' '
             << node[n].D << endl;
    }

    return 0;
}
