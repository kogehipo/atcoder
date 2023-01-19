#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ce
// 解説 


int main()
{
    // 入力
    int N;
    cin >> N;
    int A[N+1];
    A[0] = 0;
    for (int n=1; n<=N; n++) cin >> A[n];

    int Q;
    cin >> Q;
    int L[Q], R[Q];
    rep(i, 0, Q) cin >> L[i] >> R[i];

    // アタリの累積和を取る
    int S[N+1];
    S[0] = 0;
    for (int n=1; n<=N; n++) S[n] = S[n-1] + A[n];

    // 答える
    rep(i, 0, Q) {
        // LからRまでの回数
        int total = R[i]-L[i]+1;
        // LからRまでのアタリの回数
        int win = S[R[i]] - S[L[i]-1];
        int lose = total - win;
        if      (lose < win) cout << "win";
        else if (lose > win) cout << "lose";
        else                 cout << "draw";
        cout << endl;
    }

    return 0;
}
