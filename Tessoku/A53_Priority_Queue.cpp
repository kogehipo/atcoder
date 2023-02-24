#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ba
// 解説 

int main()
{
    int Q;
    cin >> Q;
    vector<int> query(Q);
    vector<int> price(Q);
    rep(i, Q) {
        cin >> query[i];
        if (query[i] == 1) cin >> price[i];
    }

    priority_queue<int, vector<int>, greater<int>> qu;
    rep(i, Q) {
        if      (query[i] == 1) qu.push(price[i]);
        else if (query[i] == 2) cout << qu.top() << endl;
        else if (query[i] == 3) qu.pop();
    }

    return 0;
}
