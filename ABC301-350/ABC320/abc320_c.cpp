#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7FFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int M;
    std::cin >> M;
    vector<std::string> S(3);
    rep(i, 3) cin >> S[i];
    int ans = INF;
    // 揃えようとする数字0〜9をtargetとする
    for (char target='0'; target<='9'; target++) {

        // 3つのリールからtarget文字を探す（それぞれのリールに複数あるかもしれない）
        vector<vector<int>> x(3);
        vector<bool> found(3, false);
        rep(i,3) {
            rep(j,M) {
                if (S[i][j] == target) {
                    x[i].push_back(j);
                    x[i].push_back(j+M);
                    x[i].push_back(j+M+M);
                    x[i].push_back(j+M+M+M);
                    found[i] = true;
                }
            }
            sort(all(x[i]));
        }
        if (!(found[0] && found[1] && found[2])) continue;

        while(x[0][0] == x[1][0] || x[1][0] == x[2][0] || x[2][0] == x[0][0]) {
            if (x[0][0] == x[1][0]) {
                if (x[0][1] <= x[1][1]) x[0].erase(x[0].begin());
                else                    x[1].erase(x[1].begin());
            }
            else if (x[0][0] == x[2][0]) {
                if (x[0][1] <= x[2][1]) x[0].erase(x[0].begin());
                else                    x[2].erase(x[2].begin());
            }
            else if (x[1][0] == x[2][0]) {
                if (x[1][1] <= x[2][1]) x[1].erase(x[1].begin());
                else                    x[2].erase(x[2].begin());
            }
        }

        int a = max(x[0][0], x[1][0]);
        a = max(a, x[2][0]);
        ans = min(ans, a);
        //cout << "target=" << target << " ans=" << x[0][0] << "," << x[1][0] << "," << x[2][0] <<" a=" << a << endl;
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
