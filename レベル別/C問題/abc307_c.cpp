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
    int aH, aW;
    cin >> aH >> aW;
    vector<string> A(aH);
    rep(i, aH) cin >> A[i];
    int bH, bW;
    cin >> bH >> bW;
    vector<string> B(bH);
    rep(i, bH) cin >> B[i];
    int xH, xW;
    cin >> xH >> xW;
    vector<string> X(xH);
    rep(i, xH) cin >> X[i];

//int K = 4;
    // Aの始点をずらす
    range(iA, 10-aH+1, 10+xH-1) {
        range(jA, 10-aW+1, 10+xW-1) {
            // Bの始点をずらす
            range(iB, 10-bH+1, 10+xH-1) {
                range(jB, 10-bW+1, 10+xW-1) {

                    // 30x30の座標系
                    vector<string> M(30, string(30, '.'));
                    // Aを配置
                    rep(i, aH) rep(j, aW) M[iA+i][jA+j] = A[i][j];
                    // Bを配置
                    rep(i, bH) rep(j, bW) if (B[i][j] == '#') M[iB+i][jB+j] = B[i][j];
//if (K) {
//rep(k,30) cout << M[k] << endl;
//cout << "-------\n";
//K--;
//}
                    // Xを(10,10)に配置
                    bool result = true;
                    rep(i, xH) rep(j, xW) if (X[i][j] != M[10+i][10+j]) result = false;
                    // Xの範囲外に’＃’があったらだめ
                    rep(i, 30) rep(j, 30)
                        if (M[i][j] == '#' && 
                            (i < 10 || 10+xH <= i || j < 10 || 10+xW <= j)) result = false;
                    if (result == true) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
