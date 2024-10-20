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
    string S; cin >>S;
    vector<bool> v(26,false);
    rep(i,S.size()) v[S[i]-'a'] = true;
    rep(i,26) {
        if (!v[i]) {
            cout << (char)('a'+i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}
