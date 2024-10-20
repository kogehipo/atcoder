#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc296/tasks/abc296_c
// 解説 尺取り法を使った

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    rep(n, N) cin >> A[n];

    // 差分を見るので正数にしてOK
    if (X<0) X = -X;

    sort(A.begin(), A.end());

    int l=0, r=0;  // ソートされていることを前提に l と r で挟み撃ちにする
    while (l < N) {  // 左から順に
        if (A[r] - A[l] == X) {  // 差がXなら探索完了
            cout << "Yes" << endl;
            return 0;
        }
        else if (A[r] - A[l] < X) {  // 差分が小さければ探索範囲を右側に伸ばす
            r++;
        }
        else if (A[r] - A[l] > X) {  // 差分が大きければ探索範囲の左端を動かす
            l++;
        }
    }

    // ここまで来たということは見つからなかった
    cout << "No" << endl;
    return 0;
}
