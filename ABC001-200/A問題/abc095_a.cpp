#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    string S;
    cin >>S;
    int ans = 700;
    rep(i,3) if (S[i] == 'o') ans += 100;
    cout << ans << endl;
    return 0;
}
