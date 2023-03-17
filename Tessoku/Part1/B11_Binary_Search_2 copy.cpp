#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cj
// 解説 

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());

    int Q;
    cin >> Q;
    vector<int> X(Q);
    rep(i, Q) cin >> X[i];

    rep(i, Q) {
        auto it = lower_bound(A.begin(), A.end(), X[i]);
        cout << it - A.begin() << endl;
    }
    return 0;
}
