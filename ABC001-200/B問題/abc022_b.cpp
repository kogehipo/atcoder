#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    int ans = 0;
    set<int> s;
    rep(i, N) {
        if (s.find(A[i]) == s.end()) {
            s.insert(A[i]);
        } else {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
