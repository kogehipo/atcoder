#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    string S; cin >>S;
    int N = S.size();
    while (2<=N) {
        N -= 2;
        if (S.substr(0,N/2) == S.substr(N/2,N/2)) {
            cout << N << endl;
            return 0;
        }
    }
    return 0;
}
