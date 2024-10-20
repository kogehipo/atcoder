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

using Graph = vector<vector<int>>;
 
int main()
{
    int N,M; cin >>N>>M;
    Graph G(N+1);  // N=頂点数（1始まり） 
    rep(i,M) {   // 辺の数だけループ
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    queue<int> Q;
    vector<int> dist(N+1, -1);  // 始点からの距離（訪問フラグを兼用）

    Q.push(1);  // BSF探索を開始するノード
    dist[1] = 0;
 
    // BFS
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();  // キュー取得
        for (int next : G[v]) {  // 頂点をすべて調べる
            if (next == 1) {
                cout << dist[v]+1 << endl;
                return 0;
            }
            if (dist[next] != -1) continue; // 既に調査済み 
            dist[next] = dist[v] + 1;  // 頂点nextの距離は1だけ大きい
            Q.push(next);  // 後で探索するのでキューに追加
        }
    }
 
    // 結果出力 (各頂点の頂点1からの距離を見る)
    //for (int v=1; v<=N; v++) cout << v << ": " << dist[v] << endl;

    cout << -1 << endl;
    return 0;
}
