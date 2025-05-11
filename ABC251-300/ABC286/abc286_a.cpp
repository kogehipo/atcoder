#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const unsigned long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    ll N, P, Q, R, S;
    cin >> N >> P >> Q >> R >> S;
    vector<int> A(N); rep(i,N) cin >> A[i];
    range(i,0,P-2) cout << A[i] << " ";
    range(i,R-1,S-1) cout << A[i] << " ";
    range(i,Q,R-2) cout << A[i] << " ";
    range(i,P-1,Q-1) cout << A[i] << " ";
    range(i,S,N-1) cout << A[i] << " ";
    cout << endl;
    return 0;
}
