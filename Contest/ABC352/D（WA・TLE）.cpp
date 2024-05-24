#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> P(N);
    rep(i, N) {
        int a;
        cin >> a;
        P[i].first = a;   // 値
        P[i].second = i;  // そのインデックス
    }
    sort(all(P));
//rep(i,N) {cout << "val=" << P[i].first << " -> idx=" << P[i].second << endl;}
    int ans = INF;
    range(i, 1, N-K) {
//cout << "i=" << i << endl;
        int minIdx = INF;
        int maxIdx = -1;
        for (int k=i; k<i+K; k++) {
//cout << "k=" << k << ' ' << P[k].first << endl;
            minIdx = min(minIdx, P[k].second);
            maxIdx = max(maxIdx, P[k].second);
        }
//cout << "minIdx=" << minIdx << " maxIdx=" << maxIdx << endl;
        ans = min(ans, maxIdx - minIdx);
    }
    cout << ans << endl;
    return 0;
}
