#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc292/tasks/abc292_a
// 解説 


int main()
{
    string S;
    cin >> S;

    //for (char c : S) cout << (char)(c - 'a' + 'A');
    for (char c : S) cout << (char)toupper(c);

    cout << endl;
    return 0;
}
