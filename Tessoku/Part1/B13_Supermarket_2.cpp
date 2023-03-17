#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cl
// 解説 

int main()
{
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    // 累積和
    for (int i=1; i<N; i++) A[i] += A[i-1];

    int ans = 0;
    int head = 0; // 尺取虫の頭
    for (int tail=0; tail<N; tail++) {  // 尺取虫の尻尾を左側に固定
        while (head < N) {
            ll sum = A[head] - (tail==0 ? 0 : A[tail-1]);
            if (sum <= K) { // 円以内で買える
                ans++;
                head++;
                if (head == N) {  // 頭が右端に到達
                    head = tail+1;
                    break;
                }
            }
            else {  // 予算を超えた
                head = tail+1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
