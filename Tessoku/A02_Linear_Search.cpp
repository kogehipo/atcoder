#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_b
// 解説 


int main()
{
    int N, X;
    cin >> N >> X;
    int A[N];
    rep(i, 0, N) cin >> A[i];
/*
    rep(i, 0, N) {
        if (A[i] == X) {
            cout << "Yes" << endl;
            return 0;
        }
    }
*/
    if (find(A, A+N, X) != A+N) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}
