#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_aq
// 解説 ぶつかって向きを変える状況について、人が入れ変わったと見なせばそのまま素通りしたのと同じこと。

int main()
{
    int N, L;
    cin >> N >> L;

    vector<int> A(N);
    vector<char> B(N);
    rep(n, N) cin >> A[n] >> B[n];

    int farest = 0;  // 出口まで最も遠い人の距離
    rep(n, N) {
        int dist;  // トンネルの出口までの距離
        if (B[n]=='E') dist = L - A[n]; // 東向きの場合
        else           dist = A[n];     // 西向きの場合
        farest = max(farest, dist);
    }
    cout << farest << endl;
    return 0;
}