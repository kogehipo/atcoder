#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

#define Z 998244353

int main()
{
    string S; cin >>S;
    ll keta = S.size();
    ll N = stoll(S);

    vector<ll> tb(N);
    tb[0] = 1;
    ll ans = 0;
    range(i, 1, N-1) {
        tb[i] = tb[i-1] % Z;
        rep(j,keta) tb[i] = (tb[i] * 10) % Z;
        ans = (ans + N * tb[i]) % Z;
    }

    //rep(i, N) cout << tb[i] << endl;

    ans = 0;
    rep(i, N) {
        ans += (N % Z * (tb[i] % Z)) % Z;
        ans = ans % Z;
    }
    cout << ans << endl;
    return 0;
}
