#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bi
// 解説 

using Graph = vector<vector<int>>;  // グラフの型エイリアス宣言

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(m, M) cin >> A[m] >> B[m];

    // グラフを定義
    Graph G(N+1);  // N=頂点数（1始まりで扱う）
 
    // グラフ入力受取 (無向グラフ)
    for (int m=0; m<M; m++) {   // 辺の数だけループ
        G[A[m]].push_back(B[m]);  // 無向グラフなので双方向を登録
        G[B[m]].push_back(A[m]);
    }

    range(n, 1 ,N) {
        cout << n << ": {";
        rep(i, G[n].size()) {
            if (0<i) cout << ", ";
            cout << G[n][i];
        }
        cout << "}" << endl;
    }
    return 0;
}
