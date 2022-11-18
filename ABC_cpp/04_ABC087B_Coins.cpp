// 問題: https://atcoder.jp/contests/abs/tasks/abc087_b
// 解説: https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, x;
    int i, j, k, s, count;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> x;

    count = 0;
    for (i=0; i<=a; i++) {
        for (j=0; j<=b; j++) {
            for (k=0; k<=c; k++) {
                s = i*500 + j*100 + k*50;
                if (s == x) count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
