// 問題： https://atcoder.jp/contests/abs/tasks/abc086_a
// 解説： https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

#define CASE 0

int main()
{
    int a, b;

    // 入力
    cin >> a >> b;

#if CASE == 0
    if ( (a*b) % 2 ) cout << "Odd"  << endl;
    else             cout << "Even" << endl;
#endif

#if CASE == 1
    // ビット演算を使用
    if      ( (a&1) == 0 ) cout << "Even" << endl;  // どちらかが偶数なら偶数
    else if ( (b&1) == 0 ) cout << "Even" << endl;
    else                   cout << "Odd"  << endl;  // どちらも奇数なら奇数
#endif

    return 0;
}
