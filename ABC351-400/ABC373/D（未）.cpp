#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define coutf cout << fixed << setprecision(8)
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))

// 要素数3以上のmin/max（C++20から）
#define min std::ranges::min
#define max std::ranges::max

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());


void dfs(const Graph &G, int v)
{
    // 訪問済みなら再帰コールしないようにしているのでこの行は不要
    // ただし、設問の不備によりこの行が必要なこともある（ALDS1_11_B）
    if (visited[v]) return;
 
    // 行きがけ処理はここに書く
 
    visited[v] = true; // vを訪問済にする
 
    for (auto next_v : G[v]) {  // v から行ける各頂点 next_v について
        if (visited[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v);  // 再帰的に探索
    }
 
    // 帰りがけ処理はここに書く
}
 
int main()
{
    int N, M;
    cin >> N >> M;
    Graph G(N+1);  // N=頂点数
 
    // グラフ入力受取 (ここでは無向グラフを想定)
    for (int m=0; m<M; m++) {   // 辺の数だけループ
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);  // 無向グラフなので双方向を登録
        G[b].push_back(a);  // 有向グラフならこの行は不要
    }
  
    // 頂点訪問したフラブ（サイズNをfalseで初期化）
    visited.assign(N+1, false);
 
    // 頂点 1 をスタートとした探索
    dfs(G, 1);

    return 0;
}
