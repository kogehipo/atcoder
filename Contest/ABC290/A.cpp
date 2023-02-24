#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc290/tasks/abc290_a
// 解説 


int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    rep(n, N) cin >> A[n];
    rep(m, M) cin >> B[m];

    int ans = 0;
    rep(m, M) {
        ans += A[B[m]-1];
    }
    cout << ans << endl;
    return 0;
}
