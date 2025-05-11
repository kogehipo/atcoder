#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ak
// 解説 A,B,Cそれぞれを通る回数はNとMから特定できる

int main()
{
    ll N, M, B;
    cin >> N >> M >> B;
    vector<int> A(N);
    rep(n, N) cin >> A[n];
    vector<int> C(M);
    rep(m, M) cin >> C[m];

    ll ans=0;
    rep(n, N) ans += A[n] * M;
    ans += B * N * M;
    rep(m, M) ans += C[m] * N;

    cout << ans << endl;
    return 0;
}
