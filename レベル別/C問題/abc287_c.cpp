#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<bool> V(N, false);  // 訪問フラグ
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    // 頂点数が辺数+1であることが条件
    if (N != M+1) {
        cout << "No" << endl;
        return 0;
    }

    // 端点を探す
    int start = -1;
    rep(i, N) {
        if (G[i].size() == 1) {
            start = i;
            break;
        }
    }
    if (start == -1) {  // 端点が見つからない
        cout << "No" << endl;
        return 0;
    }

    V[start] = true;
    int i = G[start][0];
    while (G[i].size() != 0) {
        V[i] = true;  // 訪問済み
        if (G[i].size() == 1) break; // 反対側に到達
        if (G[i].size() != 2) {
            cout << "No" << endl;
            return 0;
        }
        // 次の頂点
        if (V[G[i][0]]) i = G[i][1];
        else i = G[i][0];
    }

    // 全部通過したか確認
    rep(i, N) {
        if (!V[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
