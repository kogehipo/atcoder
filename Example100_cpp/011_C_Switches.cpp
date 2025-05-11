// 問題 https://atcoder.jp/contests/abc128/tasks/abc128_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main()
{
    // スイッチの数:N  ⊥⊥⊥...⊥
    // 電球の数:M     ○○○○...○  (i番目の電球はk個のスイッチに接続)
    int N, M;
    cin >> N >> M;

    int K[M];
    int s[M][N];
    int p[M];
    rep (m, 0, M) {
        cin >> K[m];
        rep (n, 0, K[m]) cin >> s[m][n];
    }
    rep (m, 0, M) {
        cin >> p[m];
    }

    // スイッチの状態は2^Nだけある。最大1024通りなので全探索可能
    // nの各ビットがスイッチのOn/Offを示す。
    int count = 0;
    for (int n=0; n<pow(2,N); n++) {
        // M個の電球を順に、点灯しているかどうか調べる。
        bool all_bulb_is_on = true;
        for (int m=0; m<M; m++) {
            // 繋がっているスイッチの数
            int count_on_switch = 0;
            for (int k=0; k<K[m]; k++) {
                // k番目のスイッチの状態を求める
                if (n >> (s[m][k]-1) & 0x1) count_on_switch++;
            }
            if (count_on_switch % 2 != p[m]) {
                // 点灯していない電球が一つでもあれば中断
                all_bulb_is_on = false;
                break;
            }
        }
        // 全部の電球が点灯していればカウントアップする
        if (all_bulb_is_on) count++;
    }

    cout << count << endl;

    return 0;
}
