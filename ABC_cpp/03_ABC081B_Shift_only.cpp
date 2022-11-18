// 問題: https://atcoder.jp/contests/abs/tasks/abc081_b
// 解説: https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;
    int a[201];
    for (i=0; i<n; i++) cin >> a[i];

    int count = 0;
    int odd_found = 0;
    while (1) {
        for (i=0; i<n; i++) {
            if ( a[i] & 1 ) {
                odd_found = 1;
                break;
            }
            else {
                a[i] = a[i]>>1;
            }
        }
        if (odd_found) {
            cout << count << endl;
            return 0;
        }
        count++;
    }

    return 0;
}
