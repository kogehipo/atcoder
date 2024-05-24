#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    while ((N & 0x1) == 0x0) {
        ans++;
        N >>= 1;
    }
    cout << ans << endl;
    return 0;
}
