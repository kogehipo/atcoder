#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_i
// 解説 


int main()
{
    int H, W, N;
    cin >> H >> W >> N;

    int X[H+2][W+2] = {};
    for (int i=1; i<=N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        X[a][b]++;
        X[a][d+1]--;
        X[c+1][b]--;
        X[c+1][d+1]++;
    }

    // 横方向に累積和
    for(int h=1; h<=H; h++) {
        for(int w=1; w<=W; w++) {
            X[h][w] += X[h][w-1];
        }
    }

    // 縦方向に累積和
    for(int w=1; w<=W; w++) {
        for(int h=1; h<=H; h++) {
            X[h][w] += X[h-1][w];
        }
    }

    // 出力
    for(int h=1; h<=H; h++) {
        for(int w=1; w<=W; w++) {
            if (w != 1) cout << ' ';
            cout << X[h][w];
        }
        cout << endl;
    }

    return 0;
}
