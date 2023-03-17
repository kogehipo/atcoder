#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_be
// 解説 

int main()
{
    int N, Q; cin >> N >> Q;
    vector<int> A(N+1); range(i, 1, N) cin >> A[i];
    vector<int> X(Q), Y(Q); rep(i, Q) cin >> X[i] >> Y[i];

    // M[j][N]の定義、(2のi乗)日後にどこにいるかのテーブル
    vector<vector<int>> M(31, vector<int>(N+1));
    range(i, 1, N) M[0][i] = A[i];
    range(j, 1, 30) range(i, 1, N) M[j][i] = M[j-1][ M[j-1][i] ];
/*
    // Debug
    range(j, 0, 30) {
        range(i, 1, N) cout << M[j][i] << ' ';
        cout << endl;
    }
*/
    rep(q, Q) {
        int x = X[q];
        int y = Y[q];
        //cout << "x: ";
        range(bit, 0, 30) {
            if (y & (0x1<<bit)) {
                x = M[bit][x];
            }
            //cout << x << ' ';
        }
        cout << x << endl;
    }

    return 0;
}
