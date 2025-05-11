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
    ll N;
    cin >> N;
    vector<char> A = {'0', '2', '4', '6', '8'};
    string ans = "";

    if (N==1) {
        cout << 0 << endl;
        return 0;
    }
    N--;
    while (0 < N) {
        ans += A[N%5];
        N = N/5;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}

/*
 0  2  4  6  8
20 22 24 26 28
40 42 44 46 48
*/
