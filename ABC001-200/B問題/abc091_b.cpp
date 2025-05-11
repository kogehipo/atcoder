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

int main()
{
    map<string,int> mp;
    int N; cin >>N;
    rep(i,N) {
        string s; cin >>s;
        mp[s]++;
    }
    int M; cin >>M;
    rep(i,M) {
        string t; cin >>t;
        mp[t]--;
    }
    int ans = 0;
    for (const auto& [key, value] : mp) {
        ans = max(ans,value);
    }
    cout << ans << endl;
    return 0;
}
