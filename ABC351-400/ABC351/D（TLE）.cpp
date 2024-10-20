#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int H, W;
vector<string> S(1005);

// # 磁石
// @ 磁石隣接
// . 通路
// E 訪問済み(@から変化)
// V 訪問済み(.から変化)

int count(vector<string> &map, int y, int x) {
    //cout << "y: " << y << " x: " << x << endl;
    if (y < 0 || H <= y || x < 0 || W <= x) return 0; // 範囲外
    if (map[y][x] == '#') return 0;  // 磁石
    if (map[y][x] == '@') {  // 未訪問の磁石隣接
        map[y][x] = 'E';
        return 1;
    }
    if (map[y][x] == 'E') {  // 訪問済みの磁石隣接
        return 0;
    }
    if (map[y][x] == 'V') {  // 訪問済み
        return 0;
    }
    map[y][x] = 'V';  // visited
    int cnt = 1;
    if (0 < y  ) cnt += count(map, y-1, x);
    if (y < H-1) cnt += count(map, y+1, x);
    if (0 < x  ) cnt += count(map, y, x-1);
    if (x < W-1) cnt += count(map, y, x+1);
    return cnt;
}

int main()
{
    cin >> H >> W;
    rep(i, H) cin >> S[i];

    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') continue;
            if ( (0 < i   && S[i-1][j] == '#') ||
                 (i < H-1 && S[i+1][j] == '#') ||
                 (0 < j   && S[i][j-1] == '#') ||
                 (j < W-1 && S[i][j+1] == '#') ) S[i][j] = '@';
        }
    }

    //rep(i, H) {
    //    cout << S[i] << endl;
    //}

    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') continue;
            if (S[i][j] == '@') {
                ans = max(ans, 1);
                continue;
            }

            // 調査済みのマスが隣接していたら、そのマスも調査済み
            if ( (0 < i   && S[i-1][j] == '!') ||
                 (i < H-1 && S[i+1][j] == '!') ||
                 (0 < j   && S[i][j-1] == '!') ||
                 (j < W-1 && S[i][j+1] == '!') ) {
                S[i][j] = '!';
                continue;
            }

            int y, x;
            y = i; x = j;
            vector<string> map = S;
            int cnt = count(map, y, x);
/*
            cout << "y=" << y << " x=" << x << " cnt=" << cnt << endl;
            rep(i, H) {
                cout << map[i] << endl;
            }
*/
            ans = max(ans, cnt);
            S[i][j] = '!';  // 調査済み
        }
    }
    cout << ans << endl;
    return 0;
}
