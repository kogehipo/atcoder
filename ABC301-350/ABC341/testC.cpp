#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

// ここから下はオプション。問題によって選択すること。

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}

//---------------------------------------------------
// 問題 
// 解説 


int main()
{
    int H, W, N;
    cin >> H >> W >> N;

    char T[502];
    char S[502][502];
    cin >> T;
    rep(h, H) cin >> S[h];

    int ans = 0;

    rep (h, H) {
        rep (w, W) {
            int i = h;
            int j = w;
            if (S[i][j] != '.') continue;
            bool ok = true;
            rep (n, N) {
                if      (T[n] == 'L') j--;
                else if (T[n] == 'R') j++;
                else if (T[n] == 'U') i--;
                else if (T[n] == 'D') i++;
                if (0 <= i && i < H &&
                    0 <= j && j < W &&
                    S[i][j] == '.') {
                    continue;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
