#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N; cin >> N;
    string S; cin >> S;
    if (S[(N+1)/2-1] != 'b') {
        cout << -1 << endl;
        return 0;
    }
    int l = 0;
    int r = N-1;
    int ans = 0;
    rep(i, N/2) {
        if (S[l] == 'a' && S[r] == 'c' ||
            S[l] == 'c' && S[r] == 'a' ||
            S[l] == 'b' && S[r] == 'b') {
            l++;
            r--;
            ans++;
            continue;
        }
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
