#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc288/tasks/abc288_b
// 解説 


int main()
{
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    rep(n, N) cin >> S[n];
    sort(S.begin(), S.begin()+K);
    rep(i, K) cout << S[i] << endl;
    return 0;
}
