#include <bits/stdc++.h>
using namespace std;
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_p
// 解説 

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