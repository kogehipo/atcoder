#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const unsigned long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    S = S + S;
    ll ans = LINF;
    range(i, 0, N-1) {
        ll cost = A * i;
        rep(j, N/2) {
            if (S[i+j] != S[i+N-1-j]) cost += B;
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}
