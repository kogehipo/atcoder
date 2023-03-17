#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_y
// 解説 

int main() {
    int H, W;
	cin >> H >> W;
    vector<string> C(H);
    rep(h, H) cin >> C[h];

    // dp[h][w]は、その場所に到達する方法の数
    vector<vector<ll>> dp(H, vector<ll>(W, 0));

    // 開始点またはゴールが黒なら到達できない
    if (C[0][0] == '#' || C[H-1][W-1] == '#') {
        cout << 0 << endl;
        return 0;
    }

	// 動的計画法
    rep(h, H) rep(w, W) {
        // 開始点に到達する方法は1通り
        if (h == 0 && w == 0) {
            dp[0][0] = 1;
            continue;
        }
        // ここが黒なら来れない
        if (C[h][w] == '#') {
            dp[h][w] = 0;
            continue;
        }
        // この場所(h,w)に来る方法は2通り
        dp[h][w] = 0;
        // 1. (h-1,w)から下移動してくる可能性
        if (0 < h && C[h-1][w] == '.') dp[h][w] += dp[h-1][w];
        // 2. (h,w-1)から右移動してくる可能性
        if (0 < w && C[h][w-1] == '.') dp[h][w] += dp[h][w-1];

        // Debug
    /*
        rep(h, H) {
            rep(w, W) cout << dp[h][w] << ' ';
            cout << endl;
        }
        cout << "--" << endl;
    */
	}

	cout << dp[H-1][W-1] << endl;
	return 0;
}
