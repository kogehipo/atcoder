#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_d
// 解説 


int main()
{
    int N;
    cin >> N;
    string s;

    for (int i=0; i<10; i++) {
        if (N % 2) s = s + "1";        
        else       s = s + "0";        
        N /= 2;
    }
    reverse(s.begin(), s.end());  // 文字列反転
    cout << s << endl;

    return 0;
}
