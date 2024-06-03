#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> A(N+M);
    int a;
    rep(i, N) {
        cin >> a;
        A[i] = make_pair(a, 0);
    }
    rep(i, M) {
        cin >> a;
        A[N+i] = make_pair(a, 1);
    }
    sort(all(A));
    rep(i, N+M-1) {
        if (A[i].second == 0 && A[i+1].second == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
