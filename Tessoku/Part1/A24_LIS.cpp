#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7FFFFFFF;
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_x
// 解説 LIS : 最長増加部分列問題
//           鉄則本では二段階に分けて解答を例示している。
//           GitHubでは元のdp[]ではなくL[]を使った動的計画法も示されている。
//           通常、LISの解説では、L[]を最初からDPテーブルとして、ANSWER==3の解法を使っている。

#define ANSWER 3

#if ANSWER == 1
// この解答はTLEする
int main()
{
    int N;
    cin >> N;
    vector<int> A(N+1);
    range(n, 1, N) cin >> A[n];

    // dpテーブルの定義
    // dp[n]は、最後の要素がA[n]であるような部分列の、最長の長さ
    // 最終的な答えはdp[]の最大値
    vector<int> dp(N+1, 0);

    range(n, 1, N) {
        dp[n] = 1;  // A[n]だけを使えばdp[n]は1
        range(i, 1, n-1) {  // dp[n未満]にA[n]を追加する場合は,+1
            if (A[i] < A[n]) dp[n] = max(dp[n], dp[i]+1);
        }
        // Debug
        //range(x, 1, N) cout << dp[x] << ' '; cout << endl;
    }

    int ans = 0;
    range(i, 1, N) ans = max(ans, dp[i]); // dp[]の最大値を探す
    cout << ans << endl;
    return 0;
}
#endif

#if ANSWER == 2
int main() {
	// 入力
    int N;
	cin >> N;
    vector<int> A(N+1);
    range(n, 1, N) cin >> A[n];

    // dp[n]は、最後の要素がA[n]であるような部分列の、最長の長さ
    vector<int> dp(N+1, 0);
    // L[l]は、長さlの部分列の、最後の要素として考えられる最小値。
    vector<int> L(N+1, INF);
    int LEN = 0;  // L[]をどこまで使ったか（最長部分列の長さ）
    // ※ANSWER==1ではA[n-1]まで全探索していたが、
    //  それを避けるためにL[]を使う。
    //  よく見るとdp[]はどこでも使っていない → ANSWER==3が導かれる

	// 動的計画法
	range(n, 1, N) {
		int pos = lower_bound(L.begin()+1, L.begin()+1+LEN, A[n]) - L.begin();
		dp[n] = pos;

		// 配列 L を更新
		L[dp[n]] = A[n];
		if (LEN < dp[n]) LEN += 1;

        // Debug
        //range(x, 1, N) cout << dp[x] << ' '; cout << ": ";
        //range(x, 1, LEN) cout << L[x] << ' '; cout << endl;
	}

	// 答えを出力
	cout << LEN << endl;
	return 0;
}
#endif

#if ANSWER == 3
int main() {
    int N;
	cin >> N;
    vector<int> A(N+1);
    range(n, 1, N) cin >> A[n];

    // L[l]は、長さlの部分列の、最後の要素として考えられる、最小のA[]の値。
    vector<int> L(N+1, INF);
    int LEN = 0;  // L[]をどこまで使ったか（最長部分列の長さ）

	// 動的計画法
	range (n, 1, N) {
		int pos = lower_bound(L.begin()+1, L.begin()+1+LEN, A[n]) - L.begin();
		L[pos] = A[n];
		if (LEN < pos) LEN += 1;
        // Debug
        //range(x, 1, LEN) cout << L[x] << ' '; cout << endl;
	}

	cout << LEN << endl;
	return 0;
}
#endif
