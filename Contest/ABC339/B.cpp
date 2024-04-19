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

    char G[101][101];
    rep(i, 101) rep(j, 101) G[i][j] = '.';

    int dir = 0;  // 上右下左
    int pos[2] = {0,0};
    int index[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    rep (n, N) {

        //cout << pos[0] << '/' << pos[1] << " -> ";

        if (G[pos[0]][pos[1]] == '.') {
            G[pos[0]][pos[1]] = '#';
            dir = (dir+1)%4;
        }
        else {
            G[pos[0]][pos[1]] = '.';
            dir = dir-1;
            if (dir < 0) dir = dir+4;
        }
        pos[0] += index[dir][0];
        if (pos[0] < 0) pos[0] += H;
        if (H <= pos[0]) pos[0] -= H;

        pos[1] += index[dir][1];
        if (pos[1] < 0) pos[1] += W;
        if (W <= pos[1]) pos[1] -= W;

        //////////////////
        //cout << pos[0] << '/' << pos[1] << endl;
        //rep(i, H) {
        //    rep(j, W) {
        //        cout << G[i][j];
        //    }
        //    cout << endl;
        //}
        //cout << "----" << endl;
        //////////////////

    }

    rep(i, H) {
        rep(j, W) {
            cout << G[i][j];
        }
        cout << endl;
    }

    return 0;
}
