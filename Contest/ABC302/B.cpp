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

int H, W;
vector<string> S(H);
string snuke = "uke";
int d[8][2] =
        [[-1,-1], [-1,0], [-1,1],
         [ 0,-1],         [ 0,1],
         [ 1,-1], [ 1,0], [ 1,1]];

// リターン値
// -1: snukが見つからなかった
// -1以外: snukeが見つかった方向
search_uke(int j, int i, int dir) {
    for (int k=0; snuke[k] != '\0'; k++) {
        if (snuke[k] == '\0') {
            return 見つかった;
        }
        if (S[j][i] != snuke[k]) {
            return -1;
        }
        search_uke(j+d[n][0], i+d[n][1], n+1);
    }
}

// リターン値
// -1: ８方向にnが見つからなかった
// -1以外: nが見つかったら方向を返す
int search_n(int j, int i) {
    for (int n=0; n<8; n++) {
        if (j+d[n][0] < 0 || H <= j+d[n][0]) continue;
        if (i+d[n][1] < 0 || W <= i+d[n][1]) continue;
        if (S[j+d[n][0]][i+d[n][1]] == 'n') return n;
    }
    return -1;
}

// この回答は未完
int main()
{
    cin >> H >> W;
    rep(j, H) cin >> S[j];

    range(j, 0, H-1) {
        range(i, 0, W-1) {
            if (S[j][i] != 's') continue;
            for (int n=0; n<8; n++) {
                int d = search_n(j, i);
                if (d == -1) continue;
            }
            search_uke(j, i, d);
        }
        cout << endl;
    }
    return 0;
}
