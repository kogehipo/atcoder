#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N; cin >> N;
    vector<vector<bool>> Z(101, vector<bool>(101, false));
    rep(i, N) {
        int a,b,c,d; cin>>a>>b>>c>>d;
        range(y,c,d-1) range(x,a,b-1) Z[y][x] = true;
    }
    int ans = 0;
    rep(y,101) rep(x,101) if (Z[y][x]) ans++;
    cout << ans << endl;
    return 0;
}
