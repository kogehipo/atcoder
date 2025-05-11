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
    int N; cin >>N;
    vector<int> A(N+1); rep(i,N) cin >> A[i+1];
    int ans = 0;
    int i = 1;
    while(1) {
        if (A[i] == 2) {
            cout << ans+1 << endl;
            return 0;
        }
        int next = A[i];
        if (next < 0) {
            cout << -1 << endl;
            return 0;
        }
        ans++;
        A[i] = -next;
        i = next;
    }
    return 0;
}
