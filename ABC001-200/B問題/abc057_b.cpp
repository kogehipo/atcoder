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
    int N,M; cin >>N>>M;
    vector<int> a(N),b(N),c(M),d(M);
    rep(i,N) cin >> a[i] >> b[i];
    rep(i,M) cin >> c[i] >> d[i];
    int ans = INF;
    rep(i,N) {
        int best = INF;
        rep(j,M) {
            int dist = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if (dist < best) {
                best = dist;
                ans = j;
            }
        }
        cout << ans+1 << endl;
    }
    return 0;
}
