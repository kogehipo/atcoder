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
    int N;
    cin >> N;
    vector<pair<int,int>> A(N);
    rep(i, N) {
        cin >> A[i].first;
        cin >> A[i].second;
    }
    sort(all(A));
    vector<int> l(N), r(N);
    rep(i, N) {
        l[i] = A[i].first;
        r[i] = A[i].second;
    }

    int ans = 0;
    rep(i, N) {
        int cnt;
        auto itr = lower_bound(l.begin(), l.end(), r[i]);
        //cout << "> i=" <<i << " " << r[i] << ' ' << *itr << endl;
        if (itr == l.end()) {
            cnt = N - i - 1;
            //cout << "-1 " << i << ' ' << cnt << endl;
        } else if (*itr == r[i]) {
            cnt = 1;
            //cout << "-2 " << i << ' ' << cnt << endl;
        } else {
            cnt = itr - l.begin() - (i+1);
            //cout << "-3 " << i << ' ' << cnt << endl;
        }
        if (0 < cnt) {
            ans += cnt;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
2
1 3
2 4
*/