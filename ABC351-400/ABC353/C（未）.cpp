#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N; cin >> N;
    vector<ll> A(N+1); A[0] = -1;  // 1始まり
    range(i, 1, N) {
        int a; cin >> a;
        A[i] = a % 100000000;
    }
    sort(all(A));  // 昇順ソート

    // A[i]〜A[N]の合計を求めておく
    vector<ll> S(N+1); S[0] = -1;  // 1始まり
    S[N] = A[N];
    for (int i=N-1; 1<=i; i--) {
        S[i] = S[i+1] + A[i];
    }
    //rep(i, N+1) cout << S[i] << endl;

    ll ans = 0;
    int carry;
    range(i, 1, N-1) {
        //cout << "i=" << i << endl;
        carry = N+1;  // 100000000を超えたときのindex
        range(j, i+1, N) {
            if (100000000 <= A[i] + A[j]) {
                carry = j;
                //cout << "carry=" << carry << endl;
                break;
            }
        }
        ans += A[i] * (N-i) + S[i+1];
        //cout << "ans=" << ans << endl;
        if (carry != N+1) {
            ans -= (N - carry + 1) * 100000000;
        }
    }

    cout << ans << endl;
    return 0;
}
