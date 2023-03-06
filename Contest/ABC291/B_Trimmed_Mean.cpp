#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc291/tasks/abc291_b
// 解説 

int main()
{
    int N;
    cin >> N;
    vector<int> X(N*5);
    rep(n, N*5) cin >> X[n];
    sort(X.begin(), X.end());

    double ans = 0.0;
    for (int i=N; i<4*N; i++) ans += X[i];
    cout << ans / N / 3.0 << endl;
    return 0;
}