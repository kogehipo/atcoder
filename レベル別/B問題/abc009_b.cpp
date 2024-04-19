#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    sort(rall(A));

    int ans = A[0];
    rep(i, N) {
        if (A[i] == ans) continue;
        ans = A[i];
        break;
    }

    cout << ans << endl;
    return 0;
}
