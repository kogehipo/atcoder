#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

// ここから下はオプション。問題によって選択すること。

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; }
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d
// 解説 

int main()
{
    // 星座Zodiacのデータを読み込む
    int Z;
    cin >> Z;
    Point Zd[Z];
    rep(z, 0, Z) cin >> Zd[z].x >> Zd[z].y;

    // 星Starsの情報を読み込む
    int S;
    cin >> S;
    Point St[S];
    rep(s, 0, S) cin >> St[s].x >> St[s].y;

    // すべての星についてループ
    rep(s, 0, S) {
        // 探す星座の最初の星がコレだと仮定すると移動距離は
        int dx = St[s].x - Zd[0].x;
        int dy = St[s].y - Zd[0].y;

        // 星座の残りの星についてループ
        rep(z, 1, Z) {
            //星座の星を平行移動
            Point zd;
            zd.x = Zd[z].x + dx;
            zd.y = Zd[z].y + dy;
            //この位置に星があるかどうか調べる
            set.
        }
    }


    return 0;
}
