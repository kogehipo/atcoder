// 問題 https://atcoder.jp/contests/abs/tasks/arc089_a
// 解説 https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int t, current_t, next_t;
    int x, current_x, next_x;
    int y, current_y, next_y;
    current_t = 0;
    current_x = 0;
    current_y = 0;
 
    for (int i=0; i<N; i++) {
        cin >> next_t >> next_x >> next_y;

        // 現在地との差分を求める
        t  = next_t - current_t;
        x  = abs(next_x - current_x);  // 絶対値を取らないとWAとなる
        y  = abs(next_y - current_y);

        if (t < x+y  ||        // 離れすぎていたらNo
            ((x+y)-t) % 2 ) {  // 到達した後、残りが奇数なら到達できない
            cout << "No" << endl;
            return 0;
        }

        current_t = next_t;
        current_x = next_x;
        current_y = next_y;
    }

    cout << "Yes" << endl;
    return 0;
}
