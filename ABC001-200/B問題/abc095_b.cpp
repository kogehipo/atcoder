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
    int N,X; cin >>N>>X;
    vector<int> M(N);
    rep(i,N) {
        cin >>M[i];
        X -= M[i];
    }
    int m = min(M);
    int ans = X/m + N;
    cout << ans << endl;
    return 0;
}
