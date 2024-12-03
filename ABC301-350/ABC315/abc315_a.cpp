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
    string S; cin >> S;
    rep(i,S.size()) {
        if (S[i] == 'a' ||
            S[i] == 'e' ||
            S[i] == 'i' ||
            S[i] == 'o' ||
            S[i] == 'u') continue;
        cout << S[i];
    }
    cout << endl;
    return 0;
}
