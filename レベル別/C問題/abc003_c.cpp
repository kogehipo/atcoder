#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define coutf cout << fixed << setprecision(8)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N,K;
    cin >>N>>K;
    vector<int> R(N);
    rep(i, N) cin >> R[i];
    sort(rall(R));
    double ans = 0;
    for (int i = K-1; i >= 0; i--) {
        ans = (ans + R[i]) / 2;
    }
    coutf << ans << endl;
    return 0;
}
