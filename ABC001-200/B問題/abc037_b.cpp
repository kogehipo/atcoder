#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)

int main()
{
    int N,Q; cin >>N>>Q;
    vector<int> A(N, 0);
    vector<int> L(Q), R(Q), T(Q);
    rep(i, Q) cin >>L[i]>>R[i]>>T[i];
    for (int i=Q-1; i>=0; i--) {
        range(j, L[i]-1, R[i]-1) if (A[j] == 0) A[j] = T[i];
        if (find(all(A), 0) == A.end()) break;
    }
    rep(i, N) cout << A[i] << endl;
    return 0;
}
