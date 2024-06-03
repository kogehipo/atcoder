#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N; cin >>N;
    vector<string> S(N); rep(i, N) cin >>S[i];
    vector<string> T = S;
    rep(i, N) {
        rep(j, N) {
            T[j][N-i-1] = S[i][j];
        }
    }
    rep(i, N) cout << T[i] << endl;
    return 0;
}
