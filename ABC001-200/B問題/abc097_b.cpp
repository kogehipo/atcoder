#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

// 要素数3以上のmin/max（C++20から）
#define min std::ranges::min
#define max std::ranges::max

int main()
{
    int X; cin >>X;
    int ans = 0;
    int b, p;
    if (X==1) {
        cout << 1 << endl;
        return 0;
    }
    for (b = 2; b*b<=X; b++) {
        int tmp = b;
        for (p = 2; tmp <= X; p++) { tmp *= b; if (X < tmp * b) break; }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
