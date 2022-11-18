// 問題 https://atcoder.jp/contests/abs/tasks/abc085_b
// 解説 https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int d[101];

    cin >> N;
    d[0] = 0;
    for (int i=1; i<=N; i++) cin >> d[i];

    sort(d+1, d+N+1);

    int count = 0;
    for (int i=1; i<=N; i++) {
        if (d[i] != d[i-1]) count++;
    }

    cout << count << endl;

    return 0;
}
