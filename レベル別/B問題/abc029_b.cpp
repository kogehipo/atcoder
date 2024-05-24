#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S;
    int ans = 0;
    rep(i, 12) {
        cin >> S;
        rep(k, S.size()) {
            if (S[k] == 'r') {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
