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
    int H,W,D; cin >>H>>W>>D;
    vector<string> S(H);
    rep(y,H) cin >>S[y];
    queue<pair<int,int>> Q, nextQ;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    rep(y,H) rep(x,W) {
        if (S[y][x] == 'H') {
            Q.push({y,x});
            visited[y][x] = true;
        }
    }
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    // BFS
    rep(i,D) {
        while (!Q.empty()) {
            int Y, X;
            tie(Y, X) = Q.front(); Q.pop();  // キュー取得
            rep(d,4) {
                int y = Y + dir[d].first;
                int x = X + dir[d].second;
                if (y < 0 || H <= y || x < 0 || W <= x) continue;
                if (S[y][x] == '.' && !visited[y][x]) {
                    nextQ.push({y,x});
                    visited[y][x] = true;
                }
            }
        }
        swap(Q, nextQ);
    }

    int ans = 0;
    rep(y,H) rep(x,W) {
        if (visited[y][x]) {
            ans++;
            //cout << "y=" << y << " x=" << x << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
