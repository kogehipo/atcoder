#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc298/tasks/abc298_b
// 解説 


int main()
{
    int N; cin >> N;

    //NxNの2次元配列
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));

    rep(i, N) rep(j, N) cin >> A[i][j];
    rep(i, N) rep(j, N) cin >> B[i][j];

    // 4方向の回転それぞれの結果
    bool ans0   = true;
    bool ans90  = true;
    bool ans180 = true;
    bool ans270 = true;

    rep(i, N) {
        rep(j, N) {
            if (A[i][j] == 1) {  // Aの要素が1なら調べる
                if (B[i][j]     != 1) ans0 = false;
                if (B[j][N-i-1] != 1) ans90 = false;
                if (B[N-1-i][N-1-j] != 1) ans180 = false;
                if (B[N-1-j][i]     != 1) ans270 = false;
            }
        }
    }

    if (ans0 || ans90 || ans180 || ans270) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
