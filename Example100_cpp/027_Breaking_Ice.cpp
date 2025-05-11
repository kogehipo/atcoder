// 問題 https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_d

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

#define MAX 100
int X, Y;             // 広場の大きさ。X=M, Y=N と置き換える。
int C[MAX][MAX];      // 広場の地図(Chart)  1なら氷、0なら地面
bool f[MAX][MAX];     // 割った氷を示すフラグ
int delta[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};  // ４方向への移動量

// 再帰関数は割った氷の数を返す
// y, x = 探索する座標
// count = これまでに割った氷の枚数
int break_ice(int y, int x, int count)
{
    if (C[y][x] == 0)    return count;  // 氷でなければ何もしない（同じ値を返す）
    if (f[y][x] == true) return count;  // 既に割れていたら何もしない（同じ値を返す）

    count++;         // この場所を割ったから1足して、
    f[y][x] = true;  // 割ったフラグを立てる。

    // 周囲を探索して氷を見つける
    int c = 0;
    rep(i, 0, 4) {
        int newY = y + delta[i][0];
        int newX = x + delta[i][1];
        if (newY < 0 || Y <= newY ) continue;  // 範囲外
        if (newX < 0 || X <= newX ) continue;  // 範囲外
        c = max(c, break_ice(newY, newX, count));
    }

    // 【重要】深さ方向の探索が終わったら、もう必要ないのでフラグを戻す
    f[y][x] = false;

    return max(c, count);
}

int main()
{
    // 広場の大きさを入力
    cin >> X;
    cin >> Y;

    // 地図を読み込む
    rep(y,0,Y) rep(x,0,X) cin >> C[y][x];

    // すべてのマス目を始点にして探索して、最大値を求める。
    int count = 0;
    rep(y,0,Y) rep(x,0,X) count = max(count, break_ice(y, x, 0));

    cout << count << endl;
    return 0;
}
