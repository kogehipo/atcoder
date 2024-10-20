#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N;
    cin >> N;
    vector<int> ans;
    int beki = 1;
    while(N != 0) {
        if (N & 1) {
            ans.push_back(beki);
        }
        N >>= 1;
        beki *= 2;
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) cout << ans[i] << endl;
    return 0;
}
