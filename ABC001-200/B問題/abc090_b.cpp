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

bool is_kaibun(string s)
{
    int n = s.size();
    rep(i,n/2) {
        if (s[i] != s[n-i-1]) return false;
    }
    return true;
}

int main()
{
    int A,B; cin >>A>>B;
    int ans = 0;
    range(i,A,B) {
        if (is_kaibun(to_string(i))) ans++;
    }
    cout << ans << endl;
    return 0;
}
