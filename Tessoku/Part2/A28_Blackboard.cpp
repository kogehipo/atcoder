#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ab
// 解説 

int main()
{
    int N;
    cin >> N;

    ll number = 0;
    rep(i, N) {
        char T;
        int A;
        cin >> T >> A;

        if      (T == '+') number += A;
        else if (T == '*') number *= A;
        else if (T == '-') number -= A;
        else return -1;  // ありえない

        if (number < 0) number += 10000;
        number %= 10000;
        cout << number << endl;
    }
    return 0;
}
