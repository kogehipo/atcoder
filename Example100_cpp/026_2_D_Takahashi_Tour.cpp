// 問題 https://atcoder.jp/contests/abc213/tasks/abc213_d
// 解説動画 https://www.youtube.com/watch?v=VUoZ_WU90sM&t=209s

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

#define MAX 201010

vector<vector<int>> graph(MAX);  // 接続情報。各Nodeの接続先リスト(複数なのでvectorで扱う)
bool visited[MAX];   // 訪問済みフラグ（初期値はfalse）

void dfs(int node)        // 引数は注目しているNode番号
{
	if (node != 0) cout << ' ';  // Node=0(都市1)以外は区切り文字を出力
	cout << node+1;        // 訪問したNode番号を出力
	visited[node] = true;  // 訪問済みフラグ
	sort(graph[node].begin(), graph[node].end());  // 番号の小さい順
	for (int next : graph[node]) {   // 今のNodeの接続先を順に辿る
		if(visited[next]) continue;  // 訪問済ならスキップ
		dfs(next);   // 次のNodeへ
		cout << ' ' << node+1;  // 戻ってきたので自分の番号を出力
	}
}

int main()
{
    // Nは都市の数
	int N;
	cin >> N;

	// 接続情報を整理する
	rep(i, 0, N-1) {
		int a, b; cin >> a >> b;
		a--; b--;    // Node番号(1〜)を-1して、配列添字(0〜)として使う
		// 接続先を格納する。Node番号の大小が逆転している
		// 可能性もあるので、反対方向の接続情報も登録する。
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// 根本から開始
	dfs(0);

	// 最後に改行
	cout << endl;
}
