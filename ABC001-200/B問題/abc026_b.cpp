#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N; cin >> N;
    vector<int> R(N); rep(i, N) cin >> R[i];
    sort(R.begin(), R.end(), greater<int>());
    int ans = 0;
    for (int i=0; i<N; i+=2) {
        ans += R[i]*R[i];
        if (i == N-1) break;
        ans -= R[i+1]*R[i+1];
    }
    printf("%.10f\n", (double)ans*M_PI);
    return 0;
}
