#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> B(N , 0);
    vector<vector<int>> C(N, vector<int>(N, 0));

    char ch[N];
    cin >> ch;

    int ans = 0;

    cout << ans << endl;
    return 0;
}
