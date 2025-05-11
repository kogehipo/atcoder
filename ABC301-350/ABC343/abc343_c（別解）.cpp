#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll N; cin >>N;
    ll x = (ll)cbrt(N)+1;  // 切り捨てされることを想定して、+1から始める
    for(; x>0; x--) {
        ll X = x*x*x;
        if (N < X) continue; // +1したのでN超で成立したらマズイので
        string S = to_string(X);
        bool flg = true;  // 回文判定
        rep(i,S.size()/2) {
            if (S[i] != S[S.size()-1-i]) {
                flg = false;
                break;
            }
        }
        if (flg) {
            cout << X << endl;
            return 0;
        }
    }
    return 0;
}
