#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_d
// 解説 


int main()
{
    string N;
    cin >> N;

    int ans = 0;
    for (int i=0; i<N.size(); i++) {
        ans *= 2;
        ans += N[i] - '0';
    }
    cout << ans << endl;

    return 0;
}
