#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N;
    cin >> N;

    if (N<3) {
        cout << 0 << endl;
        return 0;
    }
    else if (N==3) {
        cout << 1 << endl;
        return 0;
    }

    ll ans = 0;
    ll X[3] = {0, 0, 1};
    range(i, 4, N) {
        ans = (X[0] + X[1] + X[2]) % 10007;
        X[0] = X[1];
        X[1] = X[2];
        X[2] = ans;
    }
    cout << ans << endl;
    return 0;
}
