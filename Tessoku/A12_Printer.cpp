#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_l
// 解説 


// 時刻timeまでに印刷できる枚数を返す
ll max_print(int N, int A[], int time)
{
    ll page = 0;
    rep(n, 0, N) page += time / A[n];
    return page;
}


int main()
{
    int N, K;
    cin >> N >> K;

    int A[N];
    int min_time = INF;  // 最も早いプリンタの印刷時間
    rep(n, 0, N) {
        int a; cin >> a;
        A[n] = a;
        min_time = min(a, min_time);
    }

    // 二分探索の範囲をl〜rの間にする
    ll l, r, m;
    l = 0;  // 小さい側は0
    r = min((ll)INF, (ll)min_time*K);  // 少なくともmin_timeのK倍で印刷できる

    while (l<=r) {
        ll m = (l+r)/2;  // 中間点
        ll p = max_print(N , A, m);  // 印刷できる枚数
        if (p < K) { // K枚印刷できていないからもっと時間が必要
            l = m+1;
            if (l == r) break;
        }
        else {  // K枚以上印刷できた
            r = m;  // 探索範囲の上限を更新
            if (l == r) break;
        }
    }

    // 時間mでK枚印刷できた。さらにmを短縮できないか探索する。
    cout << r << endl;

    return 0;
}
