#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N,M,K;
    cin >>N>>M>>K;
    vector<int> C(M);
    vector<vector<int>> A(M);
    vector<char> R(M);
    rep(i, M) {
        cin >> C[i];
        A[i].resize(C[i]);
        rep(j, C[i]) cin >> A[i][j];
        cin >> R[i];
    }

    const vector<int> tb = {0x0000,
            0x0001, 0x0002, 0x0004, 0x0008,
            0x0010, 0x0020, 0x0040, 0x0080,
            0x0100, 0x0200, 0x0400, 0x0800,
            0x1000, 0x2000, 0x4000};

    int ans = 0;
    int limit = (int)(((ll)1L << N) -1);
    range(x, 0, limit) {  // ビット全探索
        bool ok = true;
        rep(i, M) {
            int cnt = 0;
            rep(j, C[i]) if (x & tb[A[i][j]]) cnt++;  // 正しい鍵の数
            if (R[i] == 'o' && K <= cnt ||  // 開いたとき、K個以上の正しい鍵が含まれているはず
                R[i] == 'x' && cnt < K) {  // 開かなかったとき、正しい鍵はK個未満
                continue;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}
