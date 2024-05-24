#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

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
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i]; 
    string snuke = "snuke";
    vector<int> Y = {1, -1, 0,  0, 1,  1, -1, -1};
    vector<int> X = {0,  0, 1, -1, 1, -1,  1, -1};

    rep(i, H) rep(j, W) {
        if (S[i][j] != 's') continue; 
        rep(dir, 8) {
            queue<int> qx, qy;
            int y = i;
            int x = j;
            rep(k, 5) {
                if (S[y][x] != snuke[k]) {
                    //cout << "Not match : " << S[y][x] << endl;
                    break;
                }
//cout << y << ":" << x << " dir=" << dir << " k=" << k << " " << S[y][x] << endl;
                qy.push(y);
                qx.push(x);
                if (k == 4) {
                    while(!qy.empty()) {
                        cout << qy.front()+1 << " " << qx.front()+1 << endl;
                        qy.pop();
                        qx.pop();
                    }
                    return 0;
                }
                y += Y[dir];
                x += X[dir];
                if (x < 0 || x >= W || y < 0 || y >= H) {
                    //cout << "Out range : " << y << " " << x << endl;
                    break;
                }
            }
            while(!qy.empty()) qy.pop();
            while(!qx.empty()) qx.pop();
        }
    }
    return 0;
}
