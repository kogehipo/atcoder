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

struct Masu {
    int v;  // そのマスの値
    vector<set<int>> p;  // そのマスに至る経路（通過した値のset）
    int n;  // そのマスに至る経路の数
};

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<Masu>> masu(H, vector<Masu>(W));
    rep(i, H) rep(j, W) {
        int x;
        cin >> x;
        masu[i][j].v = x;
        masu[i][j].n = 0;
    }

    masu[0][0].n = 1;
    set<int> s;
    s.insert(masu[0][0].v);
    masu[0][0].p.push_back(s);
    rep(i, H) rep(j, W) {
        if (0 <= i-1) {
            for (auto s : masu[i-1][j].p) {
                if (s.find(masu[i][j].v) == s.end()) {
                    s.insert(masu[i][j].v);
                    masu[i][j].p.push_back(s);
                    masu[i][j].n++;
                }
            }
        }
        if (0 <= j-1) {
            for (auto s : masu[i][j-1].p) {
                if (s.find(masu[i][j].v) == s.end()) {
                    s.insert(masu[i][j].v);
                    masu[i][j].p.push_back(s);
                    masu[i][j].n++;
                }
            }
        }
        //cout << i << ':' << j << ' ' << masu[i][j].n << endl;
    }

    cout << masu[H-1][W-1].n << endl;
    return 0;
}
