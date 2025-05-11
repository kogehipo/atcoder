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
    int N; cin >>N;
    if (N==1) {
        cout << 1 << endl;
        return 0;
    }
    ll prev2 = 2;
    ll prev1 = 1;
    ll ans;
    range(i,2,N) {
        ans = prev2 + prev1;
        prev2 = prev1;
        prev1 = ans;
    }
    cout << ans << endl;
    return 0;
}
