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
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> C(N);
    rep(i, N) cin >> C[i];

    // 各色について
    vector<int> first(M+1, -1);  // 最初に現れた位置
    vector<char> last(M+1, ' ');  // 最後に現れた文字

    // 先頭から１文字ずつ見ていく
    rep(i, N) {
        // その色の最初に現れた文字なら
        if (first[C[i]] == -1) {
            first[C[i]] = i;    // その位置を記録
            last[C[i]] = S[i];  // その文字を記録
        }
        // その色の２回目移行に現れた文字なら
        else {
            // 今の文字と最後に現れた文字を入れ替える
            char tmp = S[i];
            S[i] = last[C[i]];
            last[C[i]] = tmp;
        }
        //cout << "i=" << i << " C=" << C[i] << ' ' << S << ' ';
        //range(j, 1, M) cout << first[j];
        //range(j, 1, M) cout << last[j];
        //cout << endl;
    }

    // 各色が最初に現れた位置を、その色の最後の文字に変更
    range(i, 1, M) {
        if (last[i] != ' ') {
            S[first[i]] = last[i];
        }
    }
    cout << S << endl;
    return 0;
}
