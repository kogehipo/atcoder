#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

// ノードのデータ構造を定義
struct Node { vector<int> from; int to; int id; };

int main()
{
    int N;
    cin >> N;
    vector<Node> G(N+1);  // 1始まり

    // グラフの初期化
    range(i, 1, N) {
        G[i].from.clear();  // 入るノード
        G[i].to = -1;   // 出先のノード
        G[i].id = -1;   // 閉路のID（連結成分のいずれかのノード番号）
    }
    // グラフの構築
    rep(i, N) {
        int a;
        cin >> a;
        G[i+1].to = a;
        G[a].from.push_back(i+1);
    }
/*
    // データ確認
    range(i, 1, N) {
        for (int j : G[i].from) cout << j << " ";
        cout << "-> (" << i << ") -> " << G[i].to << endl;
    }
*/

    range(id, 1, N) {
        int node = id;  // いま注目しているノード
        if (G[node].id != -1) continue;  // すでに調査済み
        else G[node].id = id;    // マークする

        // 閉路を探す
        while (1) {
            int next = G[node].to;  // 次のノード

            // 次のノードは未訪問
            if (G[next].id == -1) {
                G[next].id = id;    // マークする
                node = next;
                continue;
            }

            // 閉路を発見
            else if (G[next].id == id) {
                int s = next;
                queue<int> qu;
                // ノードsからスタートして、sに戻るまでのノードを出力
                for (int i=s; ; i=G[i].to) {
                    qu.push(i);
                    if (G[i].to == s) {
                        cout << qu.size() << endl;
                        bool flg = true;
                        while (!qu.empty()) {
                            if (!flg) cout << ' ';
                            else flg = false;
                            cout << qu.front();
                            qu.pop();
                        }
                        cout << endl;
                        return 0;
                    }
                }
            }

            // 他の連結成分に入ってしまった
            else {
                next = G[next].id;
            }
        }
    }
    return 0;
}
