#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N, S, T;
    cin >> N >> S >> T;
    int W;
    cin >> W;
    int ans = 0;
    if (S <= W && W <= T) ans++;
    rep(i, N-1) {
        int a;
        cin >> a;
        W += a;
        if (S <= W && W <= T) ans++;
    }
    cout << ans << endl;
    return 0;
}
