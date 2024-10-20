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
    int H,W; cin >>H>>W;
    vector<string> S(H); rep(i,H) cin >> S[i];
    rep(y,H) rep(x,W) {
        if (S[y][x] == '#') continue;
        int cnt = 0;
        range(dy,-1,1) range(dx,-1,1) {
            int ny = y+dy, nx = x+dx;
            if (ny<0 || ny>=H || nx<0 || nx>=W) continue;
            if (S[ny][nx] == '#') cnt++;
        }
        S[y][x] = cnt+'0';
    }
    rep(i,H) cout << S[i] << endl;
    return 0;
}
