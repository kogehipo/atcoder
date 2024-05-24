#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n,m; cin >>n>>m;
    double H = (n%12)*30 + (360/12)*((double)m/60);
    double M = (360/60)*(double)m;
    double ans;
    ans = H-M;
    if (ans < 0) ans = -ans;
    if (ans > 180.0) ans = 360.0 - ans;
    cout << ans << endl;
    return 0;
}
