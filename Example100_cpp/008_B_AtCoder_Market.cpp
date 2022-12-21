// 問題 https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b
// 解説 中央値について https://betrue12.hateblo.jp/entry/2018/07/02/005620

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

int main()
{
    int N;
    cin >> N;
    int A[N], B[N];
    rep(n, 0, N) {
        cin >> A[n] >> B[n];
    }

    int entryNo = 0; // 入口の番号
    int exitNo = 0;  // 出口の番号

/*  これをやるとETLする。

    // A[n], B[n]の最小・最大を求める
    int minA=INF, minB=INF, maxA=0, maxB=0;
    rep(n, 0, N) {
        minA = min(minA, A[n]); maxA = max(maxA, A[n]);
        minB = min(minB, B[n]); maxB = max(maxB, B[n]);
    }

    // 入口の場所を求める
    ll total = LINF;
    rep(i, minA, maxA+1) {
        // 入口がiのとき、入り口からA点に移動する総時間
        ll sum = 0;
        rep(n, 0, N) {
            sum += abs(A[n] - i);
        }
        if (sum < total) {
            total = sum;
            entryNo = i;
        }
    }

    // 出口の場所を求める
    total = LINF;
    rep(i, minB, maxB+1) {
        // 出口がiのとき、B点から出口に移動する総時間
        ll sum = 0;
        rep(n, 0, N) {
            sum += abs(B[n] - i);
        }
        if (sum < total) {
            total = sum;
            exitNo = i;
        }
    }
*/

    sort(A, A+N);
    sort(B, B+N);
    if (N % 2) { // 奇数の場合
        entryNo = A[(N+1)/2-1];
        exitNo  = B[(N+1)/2-1];
    }
    else {  // 偶数の場合
        entryNo = (int)((ll)A[N/2-1] + A[N/2-1])/2;
        exitNo  = (int)((ll)B[N/2-1] + B[N/2-1])/2;
    }

    // 総時間を計算
    ll total = 0;
    rep(n, 0, N) {
        total += abs(A[n]-entryNo);
        total += abs(A[n]-B[n]);
        total += abs(B[n]-exitNo);
    }

    cout << total << endl;
    return 0;
}
