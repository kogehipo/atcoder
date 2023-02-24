#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc289/tasks/abc289_a
// 解説 


int main()
{
    string s;
    cin >> s;

    for (int i=0; i<s.size(); i++) {
        if (s[i]=='0') cout << '1';
        else cout << '0';
    }
    cout << endl;
    return 0;
}
