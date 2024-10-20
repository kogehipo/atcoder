#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    // 入力
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    rep(i, M) cin >> A[i];
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    // 各プレイヤーの得点を計算
    vector<int> P(N, 0);
    rep(i, N) {
        rep(j, S[i].size()) {
            if (S[i][j] == 'o') P[i] += A[j];
        }
        P[i] += i+1;
        //cout << '|' << P[i] << endl;
    }

    // 最高点
    auto it = max_element(all(P));
    int max = *it;

    rep(i, N) {
        // 既に最高点の場合
        if (P[i] == max) {
            cout << 0 << endl;
            continue;
        }

        // 未回答の問題のリストを作る
        vector<int> X(M);
        rep(j, M) if (S[i][j] == 'x') X[j] = A[j]; else X[j] = 0;  // 既に解いた問題は除外
        // 逆ソートして大きいものから調べる
        sort(rall(X));

        // 最高点を上回るために必要な点数
        int x = max - P[i] + 1;
        int count = 0;  // 何問解く必要があるか
        bool needAll = true;  // 全問解かないといけない場合
        rep(j, M) {
            if (x <= 0) {
                cout << count << endl;
                needAll = false;
                break;
            }
            x -= X[j];
            count++;
        }
        if (needAll) cout << X.size() << endl;
    }
    return 0;
}
