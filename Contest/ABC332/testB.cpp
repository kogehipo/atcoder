#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

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


int main()
{
    int K, G, M;
    cin >> K >> G >> M;

    int g = 0;
    int m = 0;

    rep(k, K) {
        if (g == G) {
            g = 0;
        }
        else if (m == 0) {
            m = M;
        }
        else {
            while (m > 0 && g < G) {
                int _m = max(0, m - G + g);
                g = min(G, g + m);
                m = _m;
            }
        }
        //cout << k << ": " << g << " " << m << endl;
    }

    cout << g << ' ' << m << endl;
    return 0;
}
