#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int N, M;
vector<vector<int>> G(10);
vector<bool> visited(10);
vector<string> S(10);

bool dfs(int i)
{
    // ここをマークする
    visited[i] = true;

    // すべて訪問済みならば完了
    bool done = true;
    rep(j, N) if (!visited[j]) done = false;
    if (done) return true;

    // 連結先をすべて調べる
    for (int j : G[i]) {
        if (visited[j]) continue;
        //cout << '(' << j << ')' << S[i] << '=' << S[j] << endl;
        if (dfs(j)) {
            return true;
        }
    }
    visited[i] = false;
    return false;
}

int main()
{
    cin >> N >> M;
    rep(i, N) cin >> S[i];

    // 距離が１のものを探す
    range(i, 0, N-2) {
        range(j, i+1, N-1) {
            int cnt = 0;
            rep(k, M) if (S[i][k] != S[j][k]) cnt++;
            if (cnt == 1) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

    // 孤立したノードがあれば"No"
    rep(i, N) {
        if (G[i].empty()) {
            cout << "No" << endl;
            return 0;
        }
    }

    // すべてのノードを１度だけ訪れるパスがあるか？
    rep(i, N) {
        rep(j, N) visited[j] = false;
        //cout << "Start with (" << i << ')' << S[i] << endl;
        if (dfs(i)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
