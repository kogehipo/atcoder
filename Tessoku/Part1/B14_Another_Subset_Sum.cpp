#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cm
// 解説 半分づつBit全探索する

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    // 0〜N-1 を、0〜M-1、M〜N-1に分ける。
    int M = N/2;
    vector<int> B;  // 大きさはM
    vector<int> C;  // 大きさはN-M
    int b = 0, c = 0;
    rep(i, N)
        if (i < M) B.push_back(A[i]);
        else       C.push_back(A[i]);

    // B[]について、部分和の可能性を列挙する。
    vector<ll> sumB;
    ll limit = 0x1 << M;
    rep(i, limit) {
        ll sum = 0;
        unsigned int mask = 0x1;
        for (int n=0; n<M; n++) {
            if (i & mask) sum += A[n];
            mask = mask << 1;
            if (100000000 < sum) { sum = -1; break; }
        }
        if (sum != -1) sumB.push_back(sum);
    }
    //rep(i, sumB.size()) cout << sumB[i] << ' ';

    // C[]について、部分和の可能性を列挙する。
    vector<ll> sumC;
    limit = 0x1 << (N-M);
    rep(i, limit) {
        ll sum = 0;
        unsigned int mask = 0x1;
        for (int n=0; n<(N-M); n++) {
            if (i & mask) sum += A[n+M];
            mask = mask << 1;
            if (100000000 < sum) { sum = -1; break; }
        }
        if (sum != -1) sumC.push_back(sum);
    }
    //rep(i, sumC.size()) cout << sumC[i] << ' ';

    for (auto b : sumB) {
        for (auto c : sumC) {
            if (b+c == K) {
                cout << "Yes" <<  endl;
                return 0;
            }
        }
    }
    cout << "No" <<  endl;
    return 0;
}
