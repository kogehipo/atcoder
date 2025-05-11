// 問題 https://atcoder.jp/contests/abc145/tasks/abc145_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main()
{
    // 町の数N(max=8)と、その座標p[N][x/y座標]
    int N, p[8][2];
    cin >> N;
    rep (i, N) cin >> p[i][0] >> p[i][1];

    // 時間節約のため、あらかじめ、各町の間の距離を求めておく
    double d[N][N];  // floatだと誤差が大きい
    rep (i, N) {
        d[i][i] = 0;
        rep2 (j, i+1, N) {
            d[i][j] = d[j][i] =
                sqrt(pow(p[i][0]-p[j][0],2) +
                     pow(p[i][1]-p[j][1],2));
        }
    }
    // 上の計算の確認
    //rep (i,N) rep (j,N) cout << "i=" << i << " j=" << j << " d=" << d[i][j] << endl;

    // この配列とnext_permutation()を使ってすべての経路を探索する
    int array[] = {0,1,2,3,4,5,6,7};

    int count = 0;  // 探索回数 = 平均の分母
    double all_sum = 0;  // 全探索の総和 = 平均の分子
    do {
        //rep (i, N) cout << array[i] << " ";
        //cout << endl;
        rep (i, N-1) {
            all_sum += d[array[i]][array[i+1]];
            //cout << d[array[i]][array[i+1]] << endl;
        }
        count++;
    } while (next_permutation(array,array+N));

    cout << setprecision(12) << all_sum/count << endl;

    return 0;
}
