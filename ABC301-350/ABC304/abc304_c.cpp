#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

// ここから下はオプション。問題によって選択すること。

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}

//---------------------------------------------------
// 問題 
// 解説 

struct Node {  // 無向グラフのノード
    bool visited;
    vector<int> to;
};

void dfs(vector<Node> &G, int node) {
    G[node].visited = true;
    for (int next : G[node].to) {
        if (G[next].visited) continue;
        dfs(G, next);
    }
}

int main()
{
    int N, D;
    cin >> N >> D;
    D = D*D;

    vector<Point> P(N+1);
    range(i, 1, N) {
        int x, y;
        cin >> x >> y;
        P[i] = {x, y};
    }

    vector<Node> G(N+1, {false});

    range(i, 1, N-1) {
        range(j, i+1, N) {
            int dx = P[i].x - P[j].x;
            int dy = P[i].y - P[j].y;
            if (dx*dx + dy*dy <= D) {
                G[j].to.push_back(i);
                G[i].to.push_back(j);
            }
        }
    }

    dfs(G, 1);
    range(i, 1, N) {
        if (G[i].visited) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}