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
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll sum = 0;
    rep(i, N) sum += A[i];

    // 最終的には、sum/N と sum/N+1 のどちらかになる
    ll center = sum/N;
    ll ansUP = 0;   // +1してsum/Nにするために必要な回数
    ll ansDOWN = 0; // -1してsum/N-1にするために必要な回数
    rep(i, N) {
        if (A[i] < center) ansUP += center - A[i];
        else if (center +1 < A[i]) ansDOWN += A[i] - (center+1);
    }
    cout << max(ansUP, ansDOWN) << endl;
    return 0;
}
