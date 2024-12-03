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
    int N; cin >>N;
    vector<int> A(N); rep(i,N) cin >> A[i];
    sort(all(A));
    rep(i,N-1) {
        if(A[i]+1 != A[i+1]) {
            cout << A[i]+1 << endl;
            return 0;
        }
    }
}
