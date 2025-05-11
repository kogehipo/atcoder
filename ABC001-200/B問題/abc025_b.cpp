#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N,A,B; cin >> N >> A >> B;
    int ans = 0;
    rep(i, N) {
        string s; cin >> s;
        int d; cin >> d;
        if (d < A) d = A;
        else if (d > B) d = B;
        if (s == "West") d = -d;
        ans += d;
    }
    if (ans == 0) cout << 0 << endl;
    else if (ans > 0) cout << "East " << ans << endl;
    else cout << "West " << -ans << endl;
    return 0;
}
