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
    int N,M,X; cin >>N>>M>>X;
    vector<int> A(M); rep(i,M) cin >>A[i];
    int l = 0, r = 0;
    rep(i,M) {
        if (0 < A[i] && A[i] < X && A[i] < N) l++;
        if (0 < A[i] && X < A[i] && A[i] < N) r++;
    }
    cout << min(l,r) << endl;
    return 0;
}
