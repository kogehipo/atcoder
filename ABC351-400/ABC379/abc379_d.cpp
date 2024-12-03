#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int Q;
    cin >> Q;
    ll time = 0;
    queue<ll> A;
    rep(q,Q) {
        int query;
        cin >> query;
        if (query == 1) {
            A.push(time);
        } else if (query == 2) {
            ll t; cin >>t;
            time += t;
        } else if (query == 3) {
            ll h;
            cin >> h;
            ll ans = 0;
            while (!A.empty()) {
                if (h <= time - A.front()) {
                    ans++;
                    A.pop();
                } else {
                    break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
