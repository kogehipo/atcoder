// 問題 https://atcoder.jp/contests/abc138/tasks/abc138_d
// 解説動画 https://www.youtube.com/watch?v=WyJvs9hL9Yc

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

vector<vector<int>> graph(201010);  // 接続情報。各Nodeの接続先リスト(複数なのでvectorで扱う)
bool visited[201010];   // 訪問済みフラグ（初期値はfalse）
int counter[201010];    // 各頂点のカウンターの値（初期値は0）

void bfs(int node) {       // 引数は注目しているNode番号
	visited[node] = true;  // 訪問済みフラグ
	for (int next : graph[node]) {   // 今のNodeの接続先を順に辿る
		if(visited[next]) continue;  // 訪問済ならスキップ
		counter[next] += counter[node];  // 足すべき値を加える
		bfs(next);   // 次のNodeへ
	}
}

int main()
{
    // Nは接続情報の数、Qは足すべき値の数
	int N, Q;
	cin >> N >> Q;

	// 接続情報を整理する
	rep(i, 0, N-1) {
		int a, b; cin >> a >> b;
		a--; b--;    // Node番号(1〜)を-1して、配列添字(0〜)として使う
		// 接続先を格納する。Node番号の大小が逆転している
		// 可能性もあるので、反対方向の接続情報も登録する。
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// 足すカウンタ値を覚えておく
	rep(q, 0, Q) {
		int p, x; cin >> p >> x;
		p--;  // ０始まり
		counter[p] += x;
	}

	// 根本から開始
	bfs(0);

	// 各頂点のカウンタを表示する
	rep(i, 0, N) {
		if (i) cout << ' ';
		cout << counter[i];
	}
	cout << endl;
}
