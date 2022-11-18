// 問題: https://atcoder.jp/contests/abs/tasks/abc081_a
// 解説: https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string masu;
    cin >> masu;

    int count = 0;
    if (masu[0] == '1') count++;
    if (masu[1] == '1') count++;
    if (masu[2] == '1') count++;
    cout << count << endl;
    return 0;
}
