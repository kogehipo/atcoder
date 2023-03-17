#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_z
// 解説 

// 素数判定
bool isPrime(int x)
{
    for (int i=2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    int Q;  cin >> Q;
    int X[Q]; rep(q, Q) cin >> X[q];

    rep(q, Q) {
        if (isPrime(X[q])) cout << "Yes" << endl;
        else               cout << "No"  << endl;
    }
    return 0;
}
