#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_al
// 解説 

int main()
{
    int D, N;
    cin >> D >> N;
    vector<int> L(N), R(N), H(N);
    rep(i, N) cin >> L[i] >> R[i] >> H[i];

    vector<int> T(D+1, 24);  // 1日の労働時間。初期値は24時間
    T[0] = 0;
    rep(i, N) {
        for (int j=L[i]; j<=R[i]; j++) {
            if (H[i] < T[j]) T[j] = H[i]; 
        }
    }

    int ans = 0;
    range(i, 1, D) ans += T[i];
    cout << ans << endl;
    return 0;
}
