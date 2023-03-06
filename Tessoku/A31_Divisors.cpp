#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ae
// 解説 

int main()
{
    ll N;
    cin >> N;

    ll by_3 = N/3;
    ll by_5 = N/5;
    ll by_15 = N/15;

    cout << by_3 + by_5 - by_15 << endl;
    return 0;
}
