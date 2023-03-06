#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ad
// 解説 

int main()
{
    int n, r;
    cin >> n >> r;
    ll C = 1;
    for (int i=0; i<r; i++) {
        C = C * (n-i);
        C = C / (r-i);
        C = C % 1000000007;
    }
    cout << C % 1000000007 << endl;
    return 0;
}
