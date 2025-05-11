#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cp
// 解説 

int main()
{
    int N; cin >> N;
    vector<int> H(N+1); range(i, 1, N) cin >> H[i];

    // dp[i]は、H[i]に辿り着くまでの最小コスト
    // from[i]は、H[i]からどこから飛んできたか
    vector<int> dp(N+1, 0);
    vector<int> from(N+1, 0);
    dp[1] = 0;
    dp[2] = abs(H[1]-H[2]);
    from[2] = 1;
    range(i, 3, N) {
        int a = dp[i-1]+abs(H[i]-H[i-1]);
        int b = dp[i-2]+abs(H[i]-H[i-2]);
        if (a < b) {
            dp[i] = a;
            from[i] = i-1;
        } else {
            dp[i] = b;
            from[i] = i-2;
        }
    }

    stack<int> st;
    int i = N;
    int K = 0;
    while (1 <= i) {
        st.push(i);
        i = from[i];
        K++;
    }
    cout << K << endl;
    while (!st.empty()) {
        i = st.top(); st.pop();
        cout << i;
        if (i == N) cout << endl;
        else        cout << ' ';
    }
    return 0;
}
