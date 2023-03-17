#include <bits/stdc++.h>
using namespace std;
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_p
// 解説 

#define ANSWER 3

#if ANSWER == 1
vector<int> A;
vector<int> B;
vector<int> memo;

int getTime(int n)
{
    if (memo[n]) return memo[n];
    if (n == 1) return 0;
    if (n == 2) return memo[n] = A[2];
    int ret = min(getTime(n-1) + A[n],
                  getTime(n-2) + B[n]);
    return memo[n] = ret;
}

int main()
{
    int N;
    cin >> N;
    range(n, 0, 1) {                  A.push_back(0); }
    range(n, 2, N) { int a; cin >> a; A.push_back(a); }
    range(n, 0, 2) {                  B.push_back(0); }
    range(n, 3, N) { int b; cin >> b; B.push_back(b); }
    range(n, 0, N) {               memo.push_back(0); }
    cout << getTime(N) << endl;
    return 0;
}
#endif

#if ANSWER == 2
// 貰う遷移形式
int main()
{
    int N;
    cin >> N;
    vector<int> A(N+1), B(N+1);
    A[0] = A[1] = 0;
    B[0] = B[1] = B[2] = 0;
    range(n, 2, N) cin >> A[n];
    range(n, 3, N) cin >> B[n];

    vector<int> dp(N+1, 0);
    dp[1] = 0;
    dp[2] = A[2];
    range(i, 3, N) {
        dp[i] = min(dp[i-1]+A[i], dp[i-2]+B[i]);
    }
    cout << dp[N] << endl;
    return 0;
}
#endif

#if ANSWER == 3
// 配る遷移形式
int main()
{
    int N;
    cin >> N;
    vector<int> A(N+1), B(N+1);
    A[0] = A[1] = 0;
    B[0] = B[1] = B[2] = 0;
    range(n, 2, N) cin >> A[n];
    range(n, 3, N) cin >> B[n];

    vector<int> dp(N+1, 1000000000);
    dp[1] = 0;
    range(i, 1, N-1) {
        dp[i+1] = min(dp[i+1], dp[i]+A[i+1]);
        if (i == N-1) continue;
        dp[i+2] = min(dp[i+2], dp[i]+B[i+2]);
    }
    cout << dp[N] << endl;
    return 0;
}
#endif

