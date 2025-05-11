// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main()
{
    int D, N, M;
    cin >> D;  // 全長
    cin >> N;  // 店舗数
    cin >> M;  // 注文数

    int d[N+1];  // 本店は２回数えて、店舗数はN+1とする
    d[0] = 0;    // d[0] は本店
    rep2 (n, 1, N) cin >> d[n];
    d[N] = D;    // d[N] は1周回った先の本店
    sort (d, d+N+1);  // この問題の場合はソートが必要

    int K[M];
    rep (m, M) cin >> K[m];

    long long sum = 0;
    rep (m, M) {
        // lower_bound()は、指定したkey以上の要素の内、
        // 一番左側の要素の位置（最小のインデックス）をイテレータで返す
        // 顧客の場所から、次の店の場所
        int next = *lower_bound(d, d+N+1, K[m]);
        // 店舗と顧客が同一場所なら距離は０
        if (next == K[m]) continue;
        // その手前の店
        int prev = *(lower_bound(d, d+N+1, K[m])-1);
        sum += min(K[m]-prev, next-K[m]);
    }

    cout << sum << endl;
    return 0;
}
