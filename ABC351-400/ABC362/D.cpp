#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (ll)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

using Graph = vector<vector<pair<ll, ll>>>;  // 重み付きグラフ
using Queue = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>; // 昇順

int main()
{
    ll N,M; cin >>N>>M;
    vector<ll> A(N+1); rep(i,N) cin >>A[i+1];
    vector<ll> U(M),V(M),B(M); rep(i,M) cin >>U[i]>>V[i]>>B[i];

	Graph G(N+1);  // 頂点数N（1始まり）
 	rep(m,M) {
		G[U[m]].push_back(make_pair(V[m], B[m]));
		G[V[m]].push_back(make_pair(U[m], B[m]));  // 無向グラフ
	}
 
	vector<ll> dist(N+1, LINF);   // 距離
	vector<bool> kakutei(N+1, false); // 距離が確定したフラグ
	dist[1] = A[1];  // 開始点の距離は0
	Queue Q;  // 探索キュー
	Q.push(make_pair(dist[1], 1));  // 探索開始頂点をキューに追加（距離,頂点番号）

	while (!Q.empty()) {
		ll v = Q.top().second; Q.pop();  // 頂点vに注目
		if (kakutei[v] == true) continue; // vの距離が既に確定
 
		// dist[x] の値を更新する
		kakutei[v] = true;
		for (auto [next, cost] : G[v]) {  // [接続先, 重み]
			if (dist[next] > dist[v] + cost + A[next]) {
				dist[next] = dist[v] + cost + A[next];
				Q.push(make_pair(dist[next], next));  //（距離,頂点番号）
			}
		}
	}

	range(i,2,N) cout << dist[i] << " ";
	//range(i,1,N) cout << dist[i] << " ";
    cout << endl;
    return 0;
}
