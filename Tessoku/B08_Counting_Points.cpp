#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cg
// 解説 

#define MAX 1500

int main()
{
    // 1501x1501の2次元vectorを0で初期化
    vector<vector<int>> map(MAX+1, vector<int>(MAX+1, 0));

    int N;
    cin >> N;

    // 座標にマーク
    rep(n, N) {
        int X, Y;
        cin >> X >> Y;
        map[Y][X]++;
    }
/*
    range(y, 1, MAX) {
        range(x, 1, MAX)
            cout << map[y][x] << ' ';
        cout << endl;
    }
    cout << endl;
*/
    // 横方向に累積和
    range(y, 1, MAX)
        range(x, 1, MAX)
            map[y][x] += map[y][x-1];
    // 縦方向に累積和
    range(x, 1, MAX)
        range(y, 1, MAX)
            map[y][x] += map[y-1][x];
/*
    range(y, 1, MAX) {
        range(x, 1, MAX)
            cout << map[y][x] << ' ';
        cout << endl;
    }
*/
    int Q;
    cin >> Q;
    vector<int> A(Q), B(Q), C(Q), D(Q);
    rep(q, Q) cin >> A[q] >> B[q] >> C[q] >> D[q]; 

    rep(q, Q) {
        cout << map[D[q]][C[q]]
                - map[D[q]][A[q]-1]
                - map[B[q]-1][C[q]]
                + map[B[q]-1][A[q]-1] << endl; 
    }
    return 0;
}
