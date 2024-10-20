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
    int A,B,C; cin >>A>>B>>C;
    vector<bool> X(B,false);
    for (int i=1; ; i++) {
        int c = (A*i)%B;
        if (c==C) {
            cout << "YES" << endl;
            return 0;
        }
        if (X[c]) {
            cout << "NO" << endl;
            return 0;
        }
        X[c] = true;
    }
    return 0;
}
