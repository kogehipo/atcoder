#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int A[3], B[3];
    rep(i, 3) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(rall(B));
    rep(i, 3) {
        rep(j, 3) {
            if (A[i] == B[j]) {
                cout << j+1 << endl;
                B[j] = -1;
            }
        }
    }
    return 0;
}
