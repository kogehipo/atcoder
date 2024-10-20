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
    cin >> M;
    vector<string> S(3);
    rep(i, 3) cin >> S[i];

    int ans = INF;

    // 揃えようとする数字0〜9をtargetとする
    range(target, '0', '9') {

        // targetが含まれていること、それが最初に現れる位置を調べる
        vector<vector<int>> x(3);  // 最初のtargetの位置
        rep(i, 3) {
            rep(j, M) {
                if (S[i][j] == target) {
                    x[i].pushback(j);
                    x[i].pushback(j+M);
                    x[i].pushback(j+M+M);
                }
            }
        }
        // ひとつでも現れなかったら次のtargetへ
        if (x[1].size() == 0) continue;
        if (x[2].size() == 0) continue;
        if (x[3].size() == 0) continue;

        // 順番を揃える
        rep(i, 3) sort(all(x[i]));

        // 3つの数字それぞれ、ボタンを押すタイミングを決めていく        
        vector<int> done(3, -1);

        // リールの中に１度しか出てこないなら、その位置に決定
        rep(i, 3) if (x[i].size() == 1) done[i] = x[i][0];

        // リールの中に２度以上出てくる場合、
        rep(i, 3) {
            if (done[i] == -1) {  // 未決定のリール

                && x[i] == x[2]) x[2] += M;


        if (x[1] == x[2]) x[2] += M;

        int t = max(x[0], x[1]);
        t = max(t, x[2]);
        ans = min(ans, t);
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
