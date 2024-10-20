#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc291/tasks/abc291_a
// 解説 

int main()
{
    string S;
    cin >> S;

    rep(i, S.size()) {
        if ('A' <= S[i] && S[i] <= 'Z') {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << S.size() << endl;
    return 0;
}