#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int A,B; cin >>A>>B;
    ll a = 1;
    ll b = 1;
    rep(i,A) a *= B;
    rep(i,B) b *= A;
    cout << a+b << endl;
    return 0;
}
