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
ll printable_pages(int N, int A[], int time)
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

    // left〜rightの範囲を二分探索する
    ll left = 0;  // 小さい側は0
    ll right = (ll)min_time * K;  // min_timeのK倍が上限

    while (left < right) {
        ll center = (left+right)/2;  // 中間点
        ll p = printable_pages(N , A, center);  // 印刷できる枚数
        if (p < K) left = center + 1; // K枚印刷できていない。もっと時間が必要
        else right = center;  // K枚以上印刷できた
    }
    cout << right << endl;
    return 0;
}
