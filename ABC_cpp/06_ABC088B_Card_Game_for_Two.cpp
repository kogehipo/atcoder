// 問題 https://atcoder.jp/contests/abs/tasks/abc088_b
// 解説 https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int a[100];
    int alice = 0, bob = 0;

    cin >> N;
    for (int i=0; i<N; i++) cin >> a[i];

    sort(a, a+N, greater<int>());

    for (int i=0; i<N; i++) {
        if (i%2) bob += a[i];
        else     alice += a[i];
    }

    cout << alice - bob << endl;

    return 0;
}
