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
    int N,K; cin >>N>>K;
    vector<int> L(N); rep(i,N) cin >> L[i];
    sort(rall(L));
    int ans = 0;
    rep(i,K) {
        ans += L[i];
    }
    cout << ans << endl;
    return 0;
}
