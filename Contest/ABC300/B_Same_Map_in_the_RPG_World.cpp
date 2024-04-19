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
// 問題 https://atcoder.jp/contests/abc300/tasks/abc300_b
// 解説 


int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<char>> A(H, vector<char>(W));
    vector<vector<char>> B(H, vector<char>(W));
    vector<vector<char>> C(H, vector<char>(W));
    rep(y, H) rep(x, W) cin >> A[y][x];
    rep(y, H) rep(x, W) cin >> B[y][x];

    rep(i, H) {
        rep(j, W) {
            // Aをy回縦シフト、x回横シフトする。これをCとする。
            rep(y, H) rep(x, W) C[y][x] = A[(y+i)%H][(x+j)%W];

            cout << "---" << i << ", " << j << endl;
            rep(y, H) {
                rep(x, W) {
                    cout << C[y][x];
                }
                cout << endl;
            }
            cout << "---" << endl;


            // CとBを比較する
            if (C == B) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
