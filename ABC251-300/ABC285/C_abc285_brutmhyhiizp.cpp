#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc285/tasks/abc285_c
// 解説 

int main()
{
    string S;
    cin >> S;
    long long ans = 0;
    rep(i, S.size()) {
        ans = ans * 26 + (S[i] - 'A' + 1);
    }
    cout << ans << endl;
    return 0;
}