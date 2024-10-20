#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

#define abs(a,b) ((a)-(b)>0?(a-b):(b-a))

int main()
{
    string S;
    cin >>S;
    int ans = 0;
    rep(i,4) {
        if (S[i] == '+') ans++;
        else ans--; 
    }
    cout << ans << endl;
    return 0;
}
