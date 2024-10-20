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
    int A,B,K; cin >>A>>B>>K;
    vector<int> X;
    rep(i,K) if (A+i <= B) X.push_back(A+i);
    rep(i,K) if (A <= B-i) X.push_back(B-i);
    sort(all(X));
    int z = -1;
    rep(i,X.size()) {
        if (X[i] != z) cout << X[i] << endl;
        z = X[i];
    }
    return 0;
}
