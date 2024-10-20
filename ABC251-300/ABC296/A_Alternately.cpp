#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc296/tasks/abc296_a
// 解説 'MM' と 'FF' の文字列が含まれるかどうか調べれば良い。

int main()
{
    int N; cin >> N;
    string S; cin >> S;

    rep (i, S.size()-1) {  // 最後からひとつ手前の位置まで
        if (S[i] == 'M' && S[i+1] == 'M') {
            cout << "No" << endl;
            return 0;
        }
        else if (S[i] == 'F' && S[i+1] == 'F') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
