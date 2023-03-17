#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ay
// 解説 

int main()
{
    int Q;
    cin >> Q;
    vector<int> query(Q);
    string name[Q];
    rep(i, Q) {
        cin >> query[i];
        if (query[i] == 1) cin >> name[i];
    }

    stack<string> st;
    rep(i, Q) {
        if      (query[i] == 1) st.push(name[i]);
        else if (query[i] == 2) cout << st.top() << endl;
        else if (query[i] == 3) st.pop();
    }

    return 0;
}
