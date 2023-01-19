#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_k
// 解説 

int main()
{
    // 入力
    int N, X;
    cin >> N >> X;

    int A[N];
    rep (i, 0, N) cin >> A[i];

    // 二分探索
    int l, r, m;
    l = 0;   // 探索範囲の左端
    r = N-1; // 探索範囲の右端
    while (l <= r) {

        // 最後のひとつ
        if (l == r) {
            m = l;
            break;
        }

        // lとrの中間
        m = (l + r)/2;

        if (X < A[m]) {
            r = m-1;
        }
        else if (A[m] < X) {
            l = m+1;
        }
        else {  // Xが見つかった
            break;
        }
    }

    if (A[m] == X) {
        cout << m+1 << endl;
        return 0;
    } else {
        cout << "Not found" << endl;
        return -1;
    }

    return 0;
}
