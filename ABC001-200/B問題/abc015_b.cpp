#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    ll ans = 0;
    int bosu = N;
    rep(i, N) {
        if (A[i] == 0) {
            bosu--;
        }
        ans += A[i];
    }
    cout << (ans+bosu-1)/bosu << endl;
    return 0;
}
