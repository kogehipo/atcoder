// 問題: https://atcoder.jp/contests/abs/tasks/abc081_b
// 解説: https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

#define CASE 1

#if CASE == 0
int main()
{
    // Nを読む
    int N;
    cin >> N;

    // Aを読む
    vector<int> A;
    rep(i, 0, N) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    int count = 0;  // 全部の数を2で割った回数
    while (1) {
        // 全部の数を調べる
        rep(i, 0, N) {
            if ( A[i] & 1 ) {  // 奇数を発見
                cout << count << endl;
                return 0;
            }
            A[i] = A[i] >> 1;  // 偶数だったら２で割る（右シフト）
        }
        count++;  // 全部偶数だった
    }

    return 0;
}
#endif

#if CASE == 1
// ２で割れる価数は、その数の2進数表記で、末尾に並ぶ0の個数
// 与えられ多数のうち、その最小値を求めれば、それが答え
int main()
{
    // Nを読む
    int N;
    cin >> N;

    int min_count = INF;  // 2で何回割れるかの最小値

    // N回繰り返す
    rep(i, 0, N) {
        int a;
        cin >> a;

        string binary = bitset<31>(a).to_string();  // 数値を31桁の2進表記に変換
        reverse(binary.begin(), binary.end());  // その文字列を反転
        int n = binary.find("1");   // 最初に現れる1の位置を調べる = 先頭の0の数
        min_count = min(min_count, n);  // その最も小さい数が求める答え
    }
    cout << min_count << endl;
    return 0;
}
#endif
