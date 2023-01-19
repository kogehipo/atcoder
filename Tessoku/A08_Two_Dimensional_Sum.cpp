#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_h
// 解説 

#define CASE 1

#if CASE == 0
// 単純にループするとTLEになる
int main()
{
    int H, W;
    cin >> H >> W;

    int X[H][W];
    rep(h, 0, H) rep(w, 0, W) cin >> X[h][w];

    int Q;
    cin >> Q;
    rep(q, 0, Q) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        ll sum = 0;
        rep(h, A-1, C) rep(w, B-1, D) sum += X[h][w];
        cout << sum << endl;
    }

    return 0;
}
#endif

#if CASE == 1
int main()
{
    int H, W;
    cin >> H >> W;

    ll X[H+1][W+1] = {0};
    rep(h, 1, H+1) rep(w, 1, W+1) cin >> X[h][w];

    // 横方向に累積和を取る
    rep(h, 1, H+1) rep(w, 1, W+1) X[h][w] += X[h][w-1];

    // 縦方向に累積和を取る
    rep(w, 1, W+1) rep(h, 1, H+1) X[h][w] += X[h-1][w];

    int Q;
    cin >> Q;
    rep(q, 0, Q) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        cout << X[C][D] - X[C][B-1] - X[A-1][D] + X[A-1][B-1] << endl;
    }

    return 0;
}
#endif
