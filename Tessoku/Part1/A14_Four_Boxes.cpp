#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_n
// 解説 

#define CASE 3

#if CASE == 0
// (N^4)回全探索ではTLEしそうなので少し工夫（結果AC）
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A, B, C, D;
    rep(i, N) { int x; cin >> x; A.push_back(x); }
    rep(i, N) { int x; cin >> x; B.push_back(x); }
    rep(i, N) { int x; cin >> x; C.push_back(x); }
    rep(i, N) { int x; cin >> x; D.push_back(x); }

    rep(a, N) rep(b, N) rep(c, N) {
        ll sum;
        sum = A[a] + B[b] + C[c];
        if (K < sum) continue;
        if (find(D.begin(), D.end(), K-sum) == D.end()) continue;
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}

#else
// テキストの通り半分全探索する
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A, B, C, D;
    rep(i, N) { int x; cin >> x; A.push_back(x); }
    rep(i, N) { int x; cin >> x; B.push_back(x); }
    rep(i, N) { int x; cin >> x; C.push_back(x); }
    rep(i, N) { int x; cin >> x; D.push_back(x); }

    vector<int> P;
    rep(a, N) rep(b, N) P.push_back(A[a] + B[b]);
    vector<int> Q;
    rep(c, N) rep(d, N) Q.push_back(C[c] + D[d]);

#if CASE == 1
    // この方法はTLEする
    rep(p, N*N) rep(q, N*N) {
        if (P[p] + Q[q] != K) continue;
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;

#elif CASE == 2
    // これだと86msでパスする
    // Qをソート
    sort(Q.begin(), Q.end());

    rep(p, N*N) {
        auto itr = lower_bound(Q.begin(), Q.end(), K-P[p]);
        if (itr != Q.end() && *itr == K-P[p]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;

#elif CASE == 3
    // しゃくとり法で試す。142msで思ったほど速くない。

    // Qをソート
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());
/*
    // Pを出力する
    cout << "P: ";
    rep(i, N*N) cout << P[i] << " ";
    cout << endl << "Q: ";
    rep(i, N*N) cout << Q[i] << " ";
    cout << endl;
*/
    // pを小さい方から、qは P[p]+Q[q] <= K を満たすところから探索開始
    int p, q;
    p = 0;
    auto itr = lower_bound(Q.begin(), Q.end(), K-P[0]);
    if (itr != Q.end()) q = itr - Q.begin();
    else                q = N*N - 1;

    while(1) {
        //cout << "p: " << p << ", q: " << q << " (" << P[p] + Q[q] << ")" << endl;
        if (P[p] + Q[q] == K) {
            cout << "Yes" << endl;
            return 0;
        }
        ++p;  // pを進める
        if (N*N <= p) break;  // pが最後まで行ったら終了
        if (K <= P[p]) break; // pがKを超えたら終了
        while (K < P[p] + Q[q]) {
            if (0 < q) q--;   // qを戻す
            else       break; // qが最初まで戻ったら終了
        }
    }
    cout << "No" << endl;
    return 0;
#endif
}
#endif
