#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_k
// 解説 

#define CASE 2

#if CASE == 0
// これでもパスする
int main()
{
    // 入力
    int N, X;
    cin >> N >> X;

    int A[N];
    rep (i, 0, N) cin >> A[i];  // 今回は0始まりで扱う

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

        // lとrの中間点を取る
        m = (l + r)/2;

        if      (X < A[m]) r = m-1;  // 答えは左半分にある
        else if (A[m] < X) l = m+1;  // 答えは右半分にある
        else break;  // Xが見つかった
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

#elif CASE == 1
// 二分探索を関数化しておいた

// 二分探索関数
// data : 任意のデータ型のvector。昇順にソートされていること。
// key  : 検索する対象
// リターン値 : keyが見つかった場合はそのオフセット
//            keyが見つからなかったら-1
template<class T>
int binary_search(const vector<T>& data, T key)
{
    int left = 0;                 // 探索範囲の左端（0始まり）
    int right = data.size() - 1;  // 探索範囲の右端

    // 二分探索
    while (left <= right) {
        int center = (left + right)/2;  // lとrの中間点
        if      (key == data[center]) return center;  // 見つかった
        else if (key < data[center])  right = center - 1;  // 答えは左半分
        else                          left  = center + 1;  // 答えは右半分
    }
    return -1;  // 見つからなかった
}

int main()
{
    // 入力
    int N, X;
    cin >> N >> X;

    vector<int> A;
    rep (i, 0, N) {
        int a; cin >> a;
        A.push_back(a);
    }

    // 二分探索
    int ans = binary_search(A, X);
    if (ans == -1) return -1;
    cout <<  ans + 1 << endl; // １始まりに変換
    return 0;
}

#elif CASE == 2
// でも本当は lower_bound() 一発で可能

int main()
{
    // 入力
    int N, X;
    cin >> N >> X;

    vector<int> A;
    rep (i, 0, N) {
        int a; cin >> a;
        A.push_back(a);
    }

    // 二分探索
    auto ans = lower_bound(A.begin(), A.end(), X); // イテレータが返る
    cout << ans - A.begin() + 1 << endl; // 先頭からの差分+1が答え
    return 0;
}
#endif
