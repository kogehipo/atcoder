#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_an
// 解説 

int main()
{
    int N;
    cin >> N;
    vector<int> A(N+1);
    rep(i, N) cin >> A[i];    
    A[N] = INF;  // 最終データのマーカーとして使用
    sort(A.begin(), A.end());  // ソートしておく

    ll ans = 0;
    ll l = -1;  // 辺の長さ
    ll n = 0;   // 同じ長さの辺が続いた回数
    rep(i, N+1) {
        if (A[i] != l) {  // 辺の長さが変わったので、それまでの経過を確認
            if (3<=n) ans += n*(n-1)*(n-2)/6;  // 3回以上続いたら正三角形を作れる
            l = A[i];  // 次の長さの辺に注目
            n = 0;  // カウンターリセット
        }
        n++;
    }
    cout << ans << endl;
    return 0;
}