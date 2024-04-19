#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N;
    cin >> N;

    vector<int> Q(N), A(N), B(N);
    rep(n, N) cin >> Q[n];
    rep(n, N) cin >> A[n];
    rep(n, N) cin >> B[n];

    // 料理Aだけ作るなら最大何個作れるか
    int maxA = INF;
    rep(i, N) if (A[i]) maxA = min(maxA, Q[i]/A[i]);

    // 最終的な答えの、Aの数は0〜maxAの範囲である。この範囲で最大値を求める
    int ans = 0;
    range(a, 0, maxA) {
        // 料理Aをm個作るときの料理Bの数
        int b = INF;
        rep(i, N) if (B[i]) b = min(b, (Q[i]-a*A[i])/B[i]);
        // 合計の料理の数
        ans = max(ans, a+b);
    }
    cout << ans << endl;
    return 0;
}
