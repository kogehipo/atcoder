#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bz
// 解説 


int main()
{
    int A, B;
    cin >> A >> B;

    for (int i=A; i<=B; i++) {
        if (100%i == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
