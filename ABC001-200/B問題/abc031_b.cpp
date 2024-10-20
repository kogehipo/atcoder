#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int L,H,N; cin >>L>>H>>N;
    vector<int> A(N); rep(i,N) cin >>A[i];
    rep(i,N) {
        if (A[i] > H) cout << -1 << endl;
        else if (A[i] <= L) cout << L - A[i] << endl;
        else cout << 0 << endl;
    }
    return 0;
}
