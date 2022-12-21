// 問題 https://atcoder.jp/contests/abs/tasks/abc085_c
// 解説 https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

int main()
{
    int N, Y;
    int a, b, c;

    cin >> N >> Y;
    Y /= 1000;

    // 合計がNになる３つの数字
    for (a=0; a<=N; a++) {          // 持っている１万円札の枚数
        for (b=0; b<=N-a; b++) {      // 持っている５千円札の枚数
            c = N - a - b;
            if (a*10 + b*5 + c == Y) {
                cout << a << ' ' << b << ' ' << c << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;
    return 0;
}
