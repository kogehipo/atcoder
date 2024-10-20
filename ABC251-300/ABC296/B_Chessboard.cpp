#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc296/tasks/abc296_b
// 解説 

int main()
{
    string S[8];
    rep (i, 8) cin >> S[i];

    rep(y, 8) {  // 上から下へ
        rep(x, 8) {  // 左から右へ
            if (S[y][x] == '*') {
                cout << (char)('a' + x) << (8 - y) << endl;
                return 0;
            }
        }
    }
    return 0;
}