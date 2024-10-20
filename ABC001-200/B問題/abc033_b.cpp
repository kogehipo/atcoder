#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N; cin >>N;
    vector<string> S(N); vector<int> P(N);
    int total = 0;
    rep(i, N) {
        cin >>S[i]>>P[i];
        total += P[i];
    }
    rep(i, N) {
        if (total/2 < P[i]) {
            cout << S[i] << endl;
            return 0;
        }
    }
    cout << "atcoder" << endl;
    return 0;
}
