#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_e
// 解説 


int main()
{
    int N, K;
    cin >> N >> K;

    int ans = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int k;
            k = K - (i+j);
            if ( 0 < k && k <= N) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
