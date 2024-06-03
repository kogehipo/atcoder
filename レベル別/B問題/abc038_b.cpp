#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)

int main()
{
    int H1,W1,H2,W2; cin >>H1>>W1>>H2>>W2;
    if (H1 == H2 || H1 == W2 || W1 == H2 || W1 == W2) {
        cout << "YES" << endl;
    }   else {
        cout << "NO" << endl;
    }
    return 0;
}
