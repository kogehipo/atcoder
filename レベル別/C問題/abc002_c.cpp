#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

#define coutf cout << fixed << setprecision(8)

int main()
{
    int x,y,a,b,c,d;
    cin >>x>>y>>a>>b>>c>>d;
    a -= x;
    b -= y;
    c -= x;
    d -= y;
    ll ans = a*d - b*c;
    if (ans < 0) ans = -ans;
    //printf("%.3f\n", (double)ans/2.0);
    coutf << (double)ans/2.0 << endl;
    //cout << (double)0.000000001 << endl;
    return 0;
}
