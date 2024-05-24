#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N,T; cin >> N >> T;
    vector<int> A(N); rep(i, N) cin >> A[i];
    int ans = 0;
    int closeTime = 0;
    rep(i, N) {
        if (A[i] < closeTime) {
            ans += T - (closeTime - A[i]);
        } else {
            ans += T;
        }
        closeTime = A[i] + T;
    }
    cout << ans << endl;
    return 0;
}
