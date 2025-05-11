#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc288/tasks/abc288_a
// 解説 


int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(n, N) cin >> A[n] >> B[n];
    rep(n, N) cout << A[n] + B[n] << endl;
    return 0;
}
