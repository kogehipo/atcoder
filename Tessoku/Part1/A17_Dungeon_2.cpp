#include <bits/stdc++.h>
using namespace std;
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_q
// 解説 

#define ANSWER 2

#if ANSWER == 1
vector<int> A;
vector<int> B;
vector<int> Time;
vector<int> from;

int getTime(int n)
{
    if (Time[n]) return Time[n];
    if (n == 1) return 0;
    if (n == 2) {
        from[2] = 1;
        return Time[2] = A[2];
    }
    int a = getTime(n-1) + A[n];
    int b = getTime(n-2) + B[n];
    if (a < b) {
        from[n] = n-1;
        return Time[n] = a;
    }
    else {
        from[n] = n-2;
        return Time[n] = b;
    }
}

int main()
{
    int N;
    cin >> N;
    range(n, 0, 1) {                  A.push_back(0); }
    range(n, 2, N) { int a; cin >> a; A.push_back(a); }
    range(n, 0, 2) {                  B.push_back(0); }
    range(n, 3, N) { int b; cin >> b; B.push_back(b); }
    range(n, 0, N) { Time.push_back(0); from.push_back(0); }

    getTime(N);

    stack<int> x;
    int k = 0;
    int n = N;
    while (1<n) { x.push(n = from[n]); k++; }
    cout << k+1 << endl;
    while (!x.empty()) {cout << x.top() << ' '; x.pop(); }
    cout << N << endl;
    return 0;
}
#endif

#if ANSWER == 2
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
    vector<int> from(N+1, -1);
    from[1] = 0;
    from[2] = 1;
    dp[1] = 0;
    dp[2] = A[2];
    range(i, 3, N) {
        int x = dp[i-1]+A[i];
        int y = dp[i-2]+B[i];
        if (x < y) {
            dp[i] = x;
            from[i] = i-1;
        } else {
            dp[i] = y;
            from[i] = i-2;
        }
    }

    stack<int> x;
    int k = 0;
    int n = N;
    while (1<n) { x.push(n = from[n]); k++; }
    cout << k+1 << endl;
    while (!x.empty()) {cout << x.top() << ' '; x.pop(); }
    cout << N << endl;
    return 0;
}
#endif