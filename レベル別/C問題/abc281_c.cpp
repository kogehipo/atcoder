#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N+1);
    vector<ll> X(N+1);
    A[0] = 0;
    X[0] = 0;
    range(i, 1, N) {
        cin >> A[i];
        X[i] = X[i-1] + A[i];
    }
    T = T%X[N];
    ll ans = 0;
    while(X[ans] < T) ans++;
    cout << ans << ' ' << T-X[ans-1] << endl;
    return 0;
}
