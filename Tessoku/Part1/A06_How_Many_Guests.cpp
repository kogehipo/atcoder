#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_ai
// 解説 


int main()
{
    int N, Q;
    cin >> N >> Q;
    int A[N+1];

    // Aを読むと同時に、累計を計算しておく
    A[0] = 0;
    rep(i, 1, N+1) {
        int a;
        cin >> a;
        A[i] = A[i-1] + a;
    }

    // 質問を読む
    int L[Q], R[Q];
    rep(i, 0, Q) {
        cin >> L[i] >> R[i];
    }

    // 答える
    rep(i, 0, Q) {
        cout << A[R[i]] - A[L[i]-1] << endl;
    }

    return 0;
}
