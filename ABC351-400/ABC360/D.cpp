#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (ll)(e); i++)
#define all(a) begin(a), end(a)

int main()
{
    ll N,T; cin >>N>>T;
    string S; cin >>S;
    ll left=0, right=0;
    rep(i,S.size()) {
        if (S[i] == '1') right++;
        else left++;
    }
    vector<ll> L(left), R(right);
    ll l = 0, r = 0;
    rep(i,N) {
        ll x; cin>> x;
        if (S[i] == '0') { L[l] = x; l++; }
        else             { R[r] = x; r++; }
    }
    sort(all(R));
    sort(all(L));
    //rep(i,right) cout << i << " " << R[i] << endl;
    //rep(i,left)  cout << i << " " << L[i] << endl;

    ll ans = 0;
    rep(r,right) {
        // この蟻の今の位置
        auto now = lower_bound(L.begin(), L.end(), R[r]);
        // T秒後の蟻の位置
        auto after = lower_bound(L.begin(), L.end(), R[r]+T*2);
        if (*after == R[r]+T*2) after++;
        ans += after - now;
    }
    cout << ans << endl;
    return 0;
}
