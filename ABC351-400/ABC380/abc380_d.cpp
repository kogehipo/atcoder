#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (ll)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    string S; cin >> S;
    ll Q; cin >>Q;
    vector<ll> K(Q); rep(i,Q) cin >>K[i];

    ll N = S.size(); // 元の文字数

    rep(q,Q) {
        char c = S[(K[q]-1)%N];

        ll x = (K[q] - 1)/N;
        int bit_count = 0;
        while(x != 0) {
            if (x % 2 == 1) bit_count++;
            x /= 2;
        }

        if (bit_count % 2 == 1) {
            if ('a' <= c && c <= 'z') cout << (char)(c-'a'+'A') << " ";
            else cout << (char)(c-'A'+'a') << " ";
        } else {
            cout << c << " ";
        }
}

    cout << endl;
    return 0;
}
