#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc298/tasks/abc298_d
// 解説 これはTLEする。vectorの代わりにdeque、modはACLのmodintを使うと速いらしい。

int main()
{
    int Q; cin >> Q;
    // 文字列Sを数値の配列で持つ
    vector<int> S(1, 1);  // 初期値は1文字、値は1

    int query, x;
    ll ans;

    rep(q, Q) {
        cin >> query;
        if (query == 1) {
            cin >> x;
            S.push_back(x);
        }
        else if (query == 2) {
            S.erase(S.begin());
        }
        else if (query == 3) {
            ans = S[0];
            for (int i=1; i<S.size(); i++) {
                //ans = (ans * 10 + S[i]) % 998244353;
                ans = ans * 10 + S[i];
                if (100000000 < ans) ans = ans % 998244353;
            }
            //cout << "> ";
            cout << ans % 998244353 << endl;
        }
    }

    return 0;
}
