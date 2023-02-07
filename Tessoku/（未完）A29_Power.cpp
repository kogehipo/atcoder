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
    int a, b;
    cin >> a >> b;

    ll ans = a;
    rep(i, b-1) {
        ans = ans * a;
        if (1000000007 < ans) ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}
