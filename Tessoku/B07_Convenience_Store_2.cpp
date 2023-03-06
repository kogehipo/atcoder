#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_al
// 解説 

int main()
{
    int T, N;
    cin >> T >> N;
    vector<int> L(N), R(N);
    rep(n, N) cin >> L[n] >> R[n];

    vector<int> time(T+1);
    rep(n, N) {
        time[L[n]]++;
        time[R[n]]--;
    }

    int total = 0;
    rep(n, T) {
        total += time[n];
        cout << total << endl;
    }
    return 0;
}
