#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    unsigned int N;
    unsigned long long X;
    cin >> N >> X;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int ans = 0;
    rep(i, N) {
        if (X & 0x1) ans += A[i];
        X = X >> 1;
    }
    cout << ans << endl;
    return 0;
}
