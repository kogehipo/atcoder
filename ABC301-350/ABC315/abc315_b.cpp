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
    int N; cin >> N;
    int year = 0;
    vector<int> D(N);
    rep(i,N) { cin >> D[i]; year += D[i]; }
    int mid = (year+1)/2;
    int m = 0;
    while(D[m] < mid) {
        mid -= D[m];
        m++;
    }
    cout << m+1 << " " << mid << endl;
    return 0;
}
