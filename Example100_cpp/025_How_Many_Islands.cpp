// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int W, H;        // 海域の幅・高さ
int c[55][55];   // 海域のマス目地図  0:海、-1:陸地 → 陸地には負値でID番号を与える。
int island_id;
queue<int> ans;

void mark_island(int h, int w)
{
    // 海なら何もしない。
    if (c[h][w] == 0) return;

    // 島の番号
    int id = c[h][w];

    // 周囲を探索して陸地を見つける
    rep(y, h-1, h+2) rep(x, w-1, w+2) {
        if (y==h && x==w) continue;
        if (y < 0 || H <= y ) continue;
        if (x < 0 || W <= x ) continue;
        if (c[y][x] == -1) {
            c[y][x] = id;
            mark_island(y, x);
        }
    }
}

int main()
{
    while (1) {   // 1回のループは1枚の海図に相当

        // 海図の大きさを入力
        cin >> W >> H;
        if (W == 0 && H == 0) break;  // 終了判定

        // 海図を読み込む
        rep(h,0,H) rep(w,0,W) {
            int a; cin >> a;
            c[h][w] = (a==1 ? -1 : 0);  // 陸地なら-1、海なら0
        }

        island_id = 0; // 島の数を初期化
        // 島判定がまだなされていない陸地を見つける
        rep(h,0,H) rep(w,0,W) {
            if (c[h][w] == -1) {
                c[h][w] = ++island_id;  // 新しい島を発見
                mark_island(h, w);  // 発見した陸地を拠点に、周囲を島IDでマークする
            }
        }
        ans.push(island_id);
    }

    // 島の数を出力
    do {
        cout << ans.front() << endl;
        ans.pop();
    } while (!ans.empty());

    return 0;
}
