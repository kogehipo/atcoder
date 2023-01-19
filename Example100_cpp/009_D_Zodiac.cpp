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
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d
// 解説 

int main()
{
    int Z, S;
    set<Point> Zd, St;
    Point p;  // ワーク用の変数

    // 星座Zodiacのデータを読み込む
    cin >> Z;
    rep(z, 0, Z) {
        cin >> p.x >> p.y;
        Zd.insert(p);
    }

    // 星Starsの情報を読み込む
    cin >> S;
    rep(s, 0, S) {
        cin >> p.x >> p.y;
        St.insert(p);
    }

    // すべての星についてループ
    for (auto s = St.begin(); s!=St.end(); s++) {

        // 星座の最初の星
        auto z = Zd.begin();

        // これが星座の最初の星だと仮定すると移動距離は
        int dx = s->x - z->x;
        int dy = s->y - z->y;

        // 星座の残りの星についてループ
        bool this_is_not_zodiac = false;
        for (z++; z!=Zd.end(); z++) {
            //星座の星を平行移動
            p.x = z->x + dx;
            p.y = z->y + dy;
            //この位置に星があるかどうか調べる
            if (St.find(p) == St.end()) {
                this_is_not_zodiac = true;  // 星はなかった
                break;
            }
        }
        if (this_is_not_zodiac) continue; // 星座ではなかったので探索を続ける
        cout << dx << ' ' << dy << endl;  // 星座を発見
        return 0;
    }
    return 0;
}
