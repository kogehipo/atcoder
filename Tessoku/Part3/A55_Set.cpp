#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bc
// 解説 

int main()
{
    int Q;
    cin >> Q;
    vector<int> query(Q);
    vector<int> x(Q);
    rep(i, Q) {
        cin >> query[i];
        cin >> x[i];
    }

    set<int> st;
    rep(i, Q) {
        if      (query[i] == 1) st.insert(x[i]);
        else if (query[i] == 2) st.erase(x[i]);
        else if (query[i] == 3) {
            auto it = lower_bound(st.begin(), st.end(), x[i]);
            if (it == st.end()) cout << "-1" << endl;
            else                cout << *it << endl;
        }
    }

    return 0;
}
