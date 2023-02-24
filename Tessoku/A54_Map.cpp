#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bb
// 解説 

int main()
{
    int Q;
    cin >> Q;
    vector<int> query(Q);
    vector<string> name(Q);
    vector<int> point(Q);
    rep(i, Q) {
        cin >> query[i];
        if (query[i] == 1) {
            cin >> name[i];
            cin >> point[i];
        }
        else if (query[i] == 2) {
            cin >> name[i];
        }
    }

    map<string, int> mp;
    rep(i, Q) {
        if      (query[i] == 1) mp[name[i]] = point[i];
        else if (query[i] == 2) cout << mp[name[i]] << endl;
    }

    return 0;
}
