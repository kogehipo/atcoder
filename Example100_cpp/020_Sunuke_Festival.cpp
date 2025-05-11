// 問題 https://atcoder.jp/contests/abc077/tasks/arc084_a

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;  // 店舗数

    int A[N], B[N], C[N];
    rep (n, 0, N) cin >> A[n]; sort(A, A+N);
    rep (n, 0, N) cin >> B[n]; sort(B, B+N);  // Bはソートしなくても良い
    rep (n, 0, N) cin >> C[n]; sort(C, C+N);

    //cout << "A: "; rep(n,N) cout << A[n] << " "; cout << endl;
    //cout << "B: "; rep(n,N) cout << B[n] << " "; cout << endl;
    //cout << "B: "; rep(n,N) cout << C[n] << " "; cout << endl;

    long long ans = 0;
    rep(b, 0, N) {  // Bに注目する
        // B[b] より小さいAの数
        long long a = lower_bound(A, A+N, B[b]) - A; 
        // B[b] より大きいCの数
        long long c = N - (upper_bound(C, C+N, B[b]) - C); 
        ans += a*c;
    }
    cout << ans << endl;
    return 0;
}
