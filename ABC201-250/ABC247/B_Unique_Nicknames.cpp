#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc247/tasks/abc247_b
// 解説 

int main()
{
    int N;
    cin >> N;
    vector<string> s(N), t(N);
    rep(n, N) cin >> s[n] >> t[n];

    multiset<string> mst;
    rep(n, N) {
        mst.insert(s[n]);
        if (s[n] != t[n]) mst.insert(t[n]);
    }

    rep(n, N) {
        if (mst.count(s[n]) == 1) continue;
        if (mst.count(t[n]) == 1) continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
