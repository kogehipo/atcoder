/*
** Unionfindを使えば簡単に解ける
*/
/*
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/dsu>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N, M;
	cin >> N >> M;
	dsu d(N);
	int ans = 0;
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;  // 0始まり
		if (d.same(a, b)) ans++;  // a,bが連結されている。閉路になってしまう
        else d.merge(a, b);  // 閉路にならないので追加
	}
	cout << ans << endl;
    return 0;
}
*/



#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) begin(a), end(a)

int N, M;
vector<vector<int>> G(200010);
vector<int> visited(200010, -1);  // 訪問フラグ（値は連結成分のID）
int id = 0;  // 連結成分の番号
int ans = 0;

// fromからつながった頂点nodeを調べる
void dfs(int from, int node)
{
    if (visited[node] != -1) return;  // すでに調査済み
    visited[node] = id;  // このノードをマーク
    rep(i, G[node].size()) {
        int to = G[node][i];  // 次の接続先
        if (to == from) continue;  // もとに戻るパスは無視
        if (visited[to] == id) ans++;  // 閉路発見（接続先が同じ閉路番号を持っている）
        else dfs(node, to);
    }
}

int main()
{
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;  // 0始まり
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(n, N) {
        id++;  // 閉路番号を更新
        dfs(-1, n);
    }
    cout << ans/2 << endl;  // 閉路は逆順でもカウントされるので2で割る
    return 0;
}
