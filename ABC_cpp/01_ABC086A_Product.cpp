// 問題： https://atcoder.jp/contests/abs/tasks/abc086_a
// 解説： https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

#if 0
    // この方法は常に乗算を実行するので遅い
    if ( (a*b) % 2 ) cout << "Odd"  << endl;
    else             cout << "Even" << endl;
#endif

    // ビット演算だけなので速い
    if      ( (a&1) == 0 ) cout << "Even" << endl;  // どちらかが偶数なら偶数
    else if ( (b&1) == 0 ) cout << "Even" << endl;
    else                   cout << "Odd"  << endl;  // どちらも奇数なら奇数

    return 0;
}
