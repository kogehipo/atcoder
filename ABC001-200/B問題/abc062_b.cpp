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

using Graph = vector<vector<int>>;

int main()
{
    int H,W; cin >>H>>W;
    vector<string> S(H);
    rep(i,H) cin >>S[i];
    rep(i,W+2) cout << '#'; cout << endl;
    rep(i,H) cout << '#' << S[i] << '#' << endl;
    rep(i,W+2) cout << '#'; cout << endl;
    return 0;
}
