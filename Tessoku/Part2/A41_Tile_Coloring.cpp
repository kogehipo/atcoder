#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ao
// 解説 最後に塗るところは3枚続きになるので、3枚続きがあればそこを最後に塗ればよい。


int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (S.find("BBB") != string::npos || S.find("RRR") != string::npos) {
            cout << "Yes" << endl;
            return 0;
    }
    cout << "No" << endl;
    return 0;
}