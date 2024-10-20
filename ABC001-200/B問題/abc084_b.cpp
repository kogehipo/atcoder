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
    int A,B; cin >>A>>B;
    string S; cin >>S;
    if (S.size() != A+B+1 || S[A] != '-') {
        cout << "No" << endl;
        return 0;
    }
    rep(i,A) {
        if (S[i] < '0' || S[i] > '9') {
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i,B) {
        if (S[i+A+1] < '0' || S[i] > '9') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
