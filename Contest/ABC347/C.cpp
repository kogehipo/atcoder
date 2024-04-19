#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (ll i=0; i < (ll)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (ll)(e); i++)

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    ll W = A+B;  // 1週間

    // 予定日Dのmodのテーブルを作る
    ll min = LINF;
    set<ll> st;
    rep(i, N) {
        ll D;
        cin >> D;
        ll mod = D%W;
        st.insert(mod);
        if (mod < min) min = mod;
    }
    // 「平日の範囲が0〜W-1をまたぐ」場合を想定して、最小値の１週間後も追加しておく
    st.insert(min+W);

    // setをvectorに変換、さらにソート
    vector<ll> v;
    for(auto s : st) v.push_back(s);
    sort(v.begin(), v.end());

    // 予定表の中に、予定なしの日が連続してB日あるかどうか調べる
    rep(i, v.size()-1) {
        ll days = v[i+1] - v[i] - 1; 
        //cout << v[i] << "〜" << v[i+1] << ' ' << days << "日" << endl;
        if (B <= days) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
