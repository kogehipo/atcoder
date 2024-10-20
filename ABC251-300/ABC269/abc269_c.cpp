#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (ll)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    ll N; cin >>N;
    ll keta;
    rep(i, 61) {
        if (N < (0x1L<<i)) {
            keta = i;
            break;
        }
    }

    //cout << "keta=" << keta << endl;
    vector<ll> data;

    ll Ones = 0;
    ll mask = 0x1L;
    rep(i, keta) {
        if (N & mask) {
            data.push_back(i);
            Ones++;
        }
        mask <<= 1;
    }

    //rep(i, data.size()) cout << data[i] << " ";
    //cout << endl;

    vector<ll> ans;
    rep(bit, 1<<Ones) {
        ll sum = 0;
        rep(i, Ones) {
            if (bit & (1<<i)) sum += 0x1L<<data[i];
        }
        cout << sum << endl;
    }
    return 0;
}
