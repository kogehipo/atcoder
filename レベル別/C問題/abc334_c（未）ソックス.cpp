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

int getStrangeValue(vector<int> A) {
    int ans = 0;
    for (int i=0; i<A.size()-1; i+=2) ans += A[i+1] - A[i];
    return ans;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    rep(i, K) cin >> A[i];

    if (K%2 == 0) {
        int ans = 0;
        for (int i=0; i<K-1; i+=2) ans += A[i+1] - A[i];
        cout << ans << endl;
        return 0;
    }

    int ans = INF;
    rep(i, K) {
        A = List;
        A.erase(A.begin()+i);
        int a = getStrangeValue(A);
        ans = min(ans, a);
        //cout << a << endl;
    }
    cout << ans << endl;
    return 0;
}
