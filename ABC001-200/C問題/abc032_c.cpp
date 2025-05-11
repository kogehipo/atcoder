#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    ll N, K;
    cin >> N >> K;

    vector<ll> s(N);
    rep(i, N) {
        cin >> s[i];
        if (s[i] == 0) {  // 0がある場合は、それだけで答えがNになる
            for (; i<N; i++) cin >> s[i]; // 読み飛ばす
            cout << N << endl;
            return 0;
        }
    }

    ll ans = 0;
    range(l, 0, N-1) {
        ll len = 0;   // 部分列の長さ
        ll x = s[l];  // 部分列の積
        if (x <= K) len = 1;
        else continue;
        //range(r, l+1, N-1) {
        ll r;
        for (r=l+1; r<=N-1; r++) {
            x *= s[r];
            if (x <= K) len++;
            else break;
        }
        ans = max(ans, len);
        if (r == N) break;  // rがNになったら、もう部分列を作っても意味がないので終了
    }
    cout << ans << endl;
    return 0;
}
