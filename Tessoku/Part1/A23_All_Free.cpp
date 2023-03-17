#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7FFFF000; // INFに対して+1する場面があるので、すこし小さくしておく
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_w
// 解説 

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(M+1, vector<int>(N+1));
    range(m, 1, M) range(n, 1, N) cin >> A[m][n];

    // dpテーブルは、
    // 縦軸：m枚目までのクーポンを使ったときの、ありうる状態一覧
    // 横軸：各商品nをビット割当して、すべての組み合わせでその商品を入手できるかどうかを示す
    // 各要素の値は、その状態を実現するのに使ったクーポン枚数
    vector<vector<int>> dp(M+1, vector<int>((0x1<<N), INF));  // 未定義状態は無限大で初期化
    dp[0][0]= 0;  // クーポン0枚で買える商品は0個(全ビット0)
    range(m, 1, M) {

        // クーポンmを使わない場合はm-1までの状態を引き継ぐ。これが初期値となる。
        range(i, 0, (0x1<<N)-1) dp[m][i] = dp[m-1][i];

        //クーポンmで買える商品をビット展開する
        int list = 0;
        range(i, 1, N) if (A[m][i] == 1) list |= 0x1<<(i-1);
        //cout << "list=" << std::bitset<8>(list) << endl;

        // ひとつ前の状態から更新する
        range(i, 0, (0x1<<N)-1) {
            if (dp[m-1][i] != INF) {
                dp[m][i|list] = min(dp[m][i|list], dp[m-1][i]+1); 
                dp[m][i|list] = min(dp[m][i|list], dp[m-1][i|list]+1); 
            }
        }
/*
        cout << "list=" << to_binary_string(list, 3) << ' ';
        range(i, 0, (0x1<<N)-1) {
            if (dp[m][i]==INF) cout << '-';
            else cout << dp[m][i];
        }
        cout << endl;
*/
    }

    if (dp[M][(0x1<<N)-1] == INF) cout << -1 << endl;
    else cout << dp[M][(0x1<<N)-1] << endl;
    return 0;
}
