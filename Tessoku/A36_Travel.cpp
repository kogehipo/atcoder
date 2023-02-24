#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_aj
// 解説 余った手数が偶数ならゴールできる


int main()
{
    int N, K;
    cin >> N >> K;

    // 最短の手数
    int min = (N-1)*2;

    // 手数が不足する場合
    if (K < min) {
        cout << "No" << endl;
        return 0;
    }

    // 余った手数が奇数ならダメ
    if ((K-min) % 2) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}
