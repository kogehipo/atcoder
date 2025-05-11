#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (ll)(e); i++)

vector<ll> weight;
vector<bool> visited;
using Graph = vector<vector<pair<ll, ll>>>;

void trace(const Graph &G, ll v)
{
    visited[v] = true;  // v を訪問済にする

//    cout << "v = " << v << " w=" << weight[v] << " ";
    for (auto next_v : G[v]) {  // v から行ける各頂点 next_v について
        if (weight[v] == LINF && weight[next_v.first] == LINF) {
            weight[v] = 0;
            weight[next_v.first] = next_v.second;
        } else if (weight[v] == LINF) {
            weight[v] = weight[next_v.first] - next_v.second;
//cout << "weight[v] = " << weight[v] << endl;
        } else if (weight[next_v.first] == LINF) {
            weight[next_v.first] = weight[v] + next_v.second;
//cout << "weight[next_v] = " << weight[next_v.first] << endl;
        }
        if (!visited[next_v.first]) trace(G, next_v.first);
    }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    Graph G(N+1);  // N=頂点数
 
    // グラフ入力受取
    for (ll m=0; m<M; m++) {   // 辺の数だけループ
        ll u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    }

    // 頂点訪問したフラブ（サイズNをfalseで初期化）
    visited.assign(N+1, false);
    weight.assign(N+1, LINF);

    // 頂点 1 をスタートとした探索
    range(i,1,N) if (!visited[i]) trace(G, i);
    range(i,1,N) cout << weight[i] << " ";
    cout << endl;
    return 0;
}
