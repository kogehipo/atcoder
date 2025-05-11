#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bm
// 解説 

using Graph = vector<vector<int>>;  // グラフの型エイリアス宣言
vector<int> count_member;  // 部下の人数

// 深さ優先探索
int dfs(const Graph &G, int v)
{
    int myStaff = 0;  // 部下の人数
 
    // 各部下について
    for (auto next_v : G[v]) { 
        if (count_member[next_v] != -1) {  // 調査済み
            myStaff += count_member[next_v] + 1;
            continue;
        }
        myStaff += dfs(G, next_v) + 1;
    }
 
    count_member[v] = myStaff;
    return myStaff;
}
 
int main()
{
    // 頂点数と辺数
    int N;
    cin >> N;

    // グラフを定義
    Graph G(N+1);  // N=頂点数
 
    // グラフ入力受取 (ここでは無向グラフを想定)
    range(n, 2, N) {   // 辺の数だけループ
        int boss;
        cin >> boss;
        G[boss].push_back(n);
    }

    // 頂点訪問したフラブ（サイズNをfalseで初期化）
    count_member.assign(N+1, -1);
 
    // 頂点 1 をスタートとした探索
    dfs(G, 1);

    range(i, 1, N) {
        if (i != 1) cout << ' ';
        cout << count_member[i];
    }
    cout << endl;
    return 0;
}