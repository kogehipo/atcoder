#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> A(N, 0);
    rep(i, N-1) {
        if (S[i] == S[i+1]) A[i+1] = A[i] + 1;
        else A[i+1] = A[i];
    }
    rep(q, Q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int ans = A[r] - A[l];
        cout << ans << endl;
    }
    return 0;
}
