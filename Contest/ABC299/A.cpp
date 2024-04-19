#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc299/tasks/abc299_a
// 解説 

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    int count = 0;
    rep(i, N) {
        if (S[i] == '|') {
            count++;
            if (count == 2) {
                cout << "out" << endl;
                return 0;
            }
        }
        else if (S[i] == '*') {
            if (count == 1) cout << "in" << endl;
            else cout << "out" << endl;
            return 0;
        }
    }
    cout << "out" << endl;
    return 0;
}

