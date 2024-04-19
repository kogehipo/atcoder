#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<string> S(1001);

void umeru(int H, int W, int y, int x) {
    S[y][x] = '-';
    if (0<y   && 0<x   && S[y-1][x-1] == '#') umeru(H, W, y-1, x-1);
    if (0<y            && S[y-1][x]   == '#') umeru(H, W, y-1, x  );
    if (0<y   && x<W-1 && S[y-1][x+1] == '#') umeru(H, W, y-1, x+1);
    if (         0<x   && S[y][x-1]   == '#') umeru(H, W, y  , x-1);
    if (         x<W-1 && S[y][x+1]   == '#') umeru(H, W, y  , x+1);
    if (y<H-1 && 0<x   && S[y+1][x-1] == '#') umeru(H, W, y+1, x-1);
    if (y<H-1          && S[y+1][x]   == '#') umeru(H, W, y+1, x  );
    if (y<H-1 && x<W-1 && S[y+1][x+1] == '#') umeru(H, W, y+1, x+1);
    return;
}

int main()
{
    int H, W;
    cin >> H >> W;
    rep(n, H) cin >> S[n];
    int ans = 0;
    rep(y, H) {
        rep(x, W) {
            if (S[y][x] == '.') continue;
            if (S[y][x] == '#') {
                umeru(H, W, y, x);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
