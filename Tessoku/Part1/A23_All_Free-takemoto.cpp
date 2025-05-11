#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7FFFF000; // INFに対して+1する場面があるので、すこし小さくしておく
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_w
// 解説 

// 再帰関数を使う方法もあるはず。次のD問題を参照。
// https://atcoder.jp/contests/abc002/tasks/abc002_4
// https://img.atcoder.jp/abc002/editorial.pdf


int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(M+1, vector<int>(N+1));
    range(m, 1, M) range(n, 1, N) cin >> A[m][n];

    // dpテーブルの定義
    // 縦軸：m枚目までのクーポンを使ったときの、ありうる状態一覧
    // 横軸：各商品をNビットに割当て、すべての組み合わせでその商品を入手できるかどうかを示す
    // 各要素の値は、その状態を実現するのに必要な枚数（最小値）
    vector<vector<int>> dp(M+1, vector<int>((0x1<<N), INF));  // 未定義状態は無限大で初期化
    dp[0][0]= 0;  // クーポン0枚で買える商品は0個(全ビット0)
    range(m, 1, M) {

        // クーポンmを使わない場合はm-1の状態を引き継ぐ。これが初期値となる。
        range(i, 0, (0x1<<N)-1) dp[m][i] = dp[m-1][i];

        //クーポンmで買える商品をビット展開する
        int list = 0;
        range(i, 1, N) if (A[m][i] == 1) list |= 0x1<<(i-1);
        list = bitset<32>()
        //cout << "list=" << bitset<8>(list) << endl;

        // ひとつ前の状態から更新する
        range(i, 0, (0x1<<N)-1) {     // ひとつ前のdpをナメて、
            if (dp[m-1][i] != INF) {  // 値がセットされていれば、
                // 現在より小さいクーポン枚数で実現できないか順次確認する
                dp[m][i|list] = min(dp[m][i|list], dp[m-1][i]+1); 
                dp[m][i|list] = min(dp[m][i|list], dp[m-1][i|list]+1); 
            }
        }
/*
        // Debug: dpをダンプ
        cout << "list=" << bitset<10>(list) << ' ';
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
