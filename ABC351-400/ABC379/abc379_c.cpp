#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    ll N,M; cin >>N>>M;
    vector<pair<ll,ll>> P(M);
    rep(i,M) cin >> P[i].first;
    rep(i,M) cin >> P[i].second;
    sort(all(P));
    vector<ll> X(M+1);
    vector<ll> A(M+1);
    ll total = 0;
    rep(i,M) {
        X[i] = P[i].first;
        A[i] = P[i].second;
        total += A[i];
    }
    if (X[0] != 1) { cout /*<< "X[0] has no stone. " << X[0]*/ << -1 << endl; return 0; }
    if (total != N) { cout /*<< "Total stones not match. " << total << " "*/ << -1 << endl; return 0; }

    // 最後に待ち受けるマスを追加
    X[M] = N+1;
    A[M] = (ll)0;

    ll ans = 0;
    bool ok = true;
    rep(i,M) {
        // 次の石が有るマスまでの隙間の大きさ
        ll gap = X[i+1] - X[i] - 1;
        // 隙間を石で埋められなければダメ
        if (A[i]-1 < gap)  { ok = false; break; }
        // 余った石を持ち越す
        A[i+1] += A[i] - (gap+1);
        // 隙間に石を置く手数
        ll n = ((A[i]-1) + (A[i]-(gap+1))) * (gap+1) / 2;
        ans += n;
    }
    if (ok && A[M] == 0) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
