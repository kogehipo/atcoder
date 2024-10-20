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
    string A,B; cin >>A>>B;
    if (A.size() > B.size()) {
        cout << "GREATER" << endl;
        return 0;
    }
    else if (A.size() < B.size()) {
        cout << "LESS" << endl;
        return 0;
    }

    rep(i, A.size()) {
        if (A[i] > B[i]) {
            cout << "GREATER" << endl;
            return 0;
        }
        else if (A[i] < B[i]) {
            cout << "LESS" << endl;
            return 0;
        }
    }

    cout << "EQUAL" << endl;
    return 0;
}
