#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ch
// 解説 

#define MAX 1500

int main()
{
    // 1501x1501の2次元vectorを0で初期化
    vector<vector<int>> map(MAX+2, vector<int>(MAX+2, 0));  // サイズは0〜1501まで

    int N;
    cin >> N;

    // 座標にマーク
    rep(n, N) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        map[B][A]++;
        map[B][C]--;
        map[D][A]--;
        map[D][C]++;
    }

    // 横方向に累積和
    range(y, 0, MAX+1)
        range(x, 1, MAX+1)
            map[y][x] += map[y][x-1];
    // 縦方向に累積和
    range(x, 0, MAX+1)
        range(y, 1, MAX+1)
            map[y][x] += map[y-1][x];
/*
    range(y, 0, MAX+1) {
        range(x, 0, MAX+1)
            cout << map[y][x] << ' ';
        cout << endl;
    }
*/
    int ans = 0;
    range(y, 0, MAX) {
        range(x, 0, MAX)
            if (map[y][x]) ans++;
    }
    cout << ans << endl;
    return 0;
}
