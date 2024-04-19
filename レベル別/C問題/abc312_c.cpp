#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int S, B;
    cin >> S >> B;
    vector<int> sell(S); // 売値 
    vector<int> buy(B);  // 買値
    rep(i, S) cin >> sell[i];
    rep(i, B) cin >> buy[i];
    sort(all(sell));
    sort(all(buy));

    // 売人の数が変化するのは、(売値-1)〜(売値) の間
    // 買人の数が変化するのは、(買値)〜(買値+1) の間
    // この4通りのチェックポインを調べる
    set<int> st;  // 重複を除去
    rep(i, S) { st.insert(sell[i]-1); st.insert(sell[i]); }
    rep(i, B) { st.insert(buy[i]); st.insert(buy[i]+1); }
    vector<int> cp;
    for (auto x : st) cp.push_back(x);
    sort(all(cp));
    int P = cp.size();

    int m;
    for (m=0; m<P; m++) {
        // 売っても良い人の数
        int s = lower_bound(all(sell), cp[m]+1) - sell.begin();
        // 買っても良い人の数
        int b = buy.end() - lower_bound(all(buy), cp[m]);
        //cout << "price:" << cp[m] << " s:" << s << " b: " << b << endl;
        if (b <= s) break;
    }
    cout << cp[m] << endl;
    return 0;
}
