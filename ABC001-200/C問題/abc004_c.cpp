#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define coutf cout << fixed << setprecision(8)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

#define swap(a,b) {int tmp = a; a = b; b = tmp;}

int main()
{
    int N;
    cin >>N;
    vector<int> A = {0, 1, 2, 3, 4, 5, 6};
    N %= 30;
    rep(i, N) swap(A[i%5+1], A[i%5+2]);
    range(i, 1, 6) cout << A[i];
    cout << endl;
    return 0;
}
