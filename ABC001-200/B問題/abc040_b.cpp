#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)

int main()
{
    int n; cin >>n;
    int x = (int)sqrt(n);
    int ans = 1e9;
    for (; 0<x; x--) {
        int y = n / x;
        int m = n - x * y;
        //cout << "x=" << x << " y=" << y << " x*y=" << x*y << " m=" << m << " ans =" << m+abs(x-y) << endl;
        ans = min(ans, m+abs(x-y));
    }
    cout << ans << endl;
    return 0;
}
