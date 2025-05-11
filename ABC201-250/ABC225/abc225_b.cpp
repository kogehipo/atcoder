#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define coutf cout << fixed << setprecision(8)
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

int main()
{
    int N; cin >>N;
    vector<int> A(N),B(N); rep(i,N-1) cin >>A[i]>>B[i];
    vector<bool> flg(N+1, false);
    int root;

    if      (A[0] == A[1] || A[0] == B[1]) root = A[0];
    else if (B[0] == A[1] || B[0] == B[1]) root = B[0];
    else {
        cout << "No" << endl;
        return 0;
    }
    //cout << "root=" << root << endl;
    flg[root] = true;

    rep(i, N-1) {
        if (A[i] == root) {
            if (flg[B[i]]) {
                cout << "No" << endl;
                return 0;
            }
            flg[B[i]] = true;
        }
        else if (B[i] == root) {
            if (flg[A[i]]) {
                cout << "No" << endl;
                return 0;
            }
            flg[A[i]] = true;
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }

    range(i, 1, N) {
        if (!flg[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
