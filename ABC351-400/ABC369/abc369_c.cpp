#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (ll)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define coutf cout << fixed << setprecision(8)
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))

// 要素数3以上のmin/max（C++20から）例.min({1,2,3})
//#define min std::ranges::min
//#define max std::ranges::max

int main()
{
    ll N; cin >>N;
    vector<ll> A(N); rep(i,N) cin >> A[i];
    ll ans = N + (N-1);

    rep(i,N-1) {
        ll x = 0;
        while(A[i+1] - A[i] == A[i+2] - A[i+1]) { x++; i++; }
        if (x != 0) ans += (x+1)*x/2;
    }

    cout << ans << endl;
    return 0;
}
