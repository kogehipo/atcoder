// 問題: https://atcoder.jp/contests/abs/tasks/abc087_b
// 解説: https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

int main()
{
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int count = 0;  // ちょうどXになる場合の数
    rep(i, 0, A+1) {
        rep(j, 0, B+1) {
            rep(k, 0, C+1) {
                int sum = i*500 + j*100 + k*50;
                if (sum == X) count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
