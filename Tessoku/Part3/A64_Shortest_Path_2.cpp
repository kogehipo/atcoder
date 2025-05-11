// ダイクストラ法
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bl

// 入力データ形式
// N M    Nは頂点数、Mは辺数（頂点番号は1始まり）
// a[1] b[1] c[1]   c[]は重み
// a[2] b[2] c[2]
//  ...
// a[M] b[M] c[M]
 
/* データ例
6 7
1 2 15
1 4 20
2 3 65
2 5 4
3 6 50
4 5 30
5 6 8
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7FFFFFFF;
using Graph = vector<vector<pair<int, int>>>;  // 重み付きグラフ
using Queue = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>; // 昇順

int main()
{
	int N, M; cin >> N >> M;

	Graph G(N+1);  // 頂点数N（1始まり）

	for (int m=0; m<M; m++) {
		int a, b, c; cin >> a >> b >> c;
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));  // 無向グラフ
	}

	vector<int> dist(N+1, INF);   // 距離
	vector<bool> kakutei(N+1, false); // 距離が確定したフラグ
	dist[1] = 0;  // 開始点の距離は0
	Queue Q;  // 探索キュー
	Q.push(make_pair(dist[1], 1));  // 探索開始頂点をキューに追加（距離,頂点番号）

	while (!Q.empty()) {
		int v = Q.top().second; Q.pop();  // 頂点vに注目
		if (kakutei[v] == true) continue; // vの距離が既に確定

		// dist[x] の値を更新する
		kakutei[v] = true;
		for (auto [next, cost] : G[v]) {  // [接続先, 重み]
			if (dist[next] > dist[v] + cost) {
				dist[next] = dist[v] + cost;
				Q.push(make_pair(dist[next], next));  //（距離,頂点番号）
			}
		}
	}

	for (int i=1; i<=N; i++) {
		if (dist[i] == INF) cout << "-1" << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}