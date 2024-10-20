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
#define coutf cout << fixed << setprecision(8)

// 要素数3以上のmin/max（C++20から）
#define min std::ranges::min
#define max std::ranges::max

int main()
{
    string S; cin >>S;

    vector<vector<int>> T(26);
    rep(i,S.size()) {
        int c = S[i] - 'A';
        T[c].push_back(i);
    }

    rep(i,26) {
        if (T[i].size() == 0) continue;
        cout << (char)('A'+i) << ":";
        rep(j,T[i].size()) cout << T[i][j] << " ";
        cout << endl;
    }

    ll ans = 0;
    rep(c,26) {
        int N = T[c].size();
        if (N < 2) continue;
        range(i,0,N-2) range(j,i+1,N-1) {
            int x = T[c][j] - T[c][i];
            if (x < 2) continue;
            //cout << T[c][i] << "-" << T[c][j] << endl;
            ans += x-1;
        }
    }
    cout << ans << endl;
    return 0;
}
