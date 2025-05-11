#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    ll total = 0;
    rep(i, N) total += B[i];
    if (total <= K) {
        cout << 1 << endl;
        return 0;
    }

    vector<pair<ll, ll>> D;  // 日、減る薬の量
    rep(i, N) {
        pair<ll,ll> d = make_pair(A[i]+1, B[i]);
        D.push_back(d);
    }
    sort(all(D));

    ll ans;
    rep(i, D.size()) {
        total -= D[i].second;
        if (total <= K) {
            ans = D[i].first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
