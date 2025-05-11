#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_c
// 解説 


int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> P;
    vector<int> Q;
    rep(i, 0, N) { int p; cin >> p; P.push_back(p); }
    rep(i, 0, N) { int q; cin >> q; Q.push_back(q); }

    rep(i, 0, N) {
        if (find(Q.begin(), Q.end(), K-P[i]) != Q.end()) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
