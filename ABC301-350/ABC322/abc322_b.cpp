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
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    bool head = true;
    rep(i, N) {
        if (S[i] != T[i]) {
            head = false;
            break;
        }
    }
    bool tail = true;
    rep(i, N) {
        if (S[N-1-i] != T[M-1-i]) {
            tail = false;
            break;
        }
    }
    if (head && tail) cout << 0 << endl;
    else if (head) cout << 1 << endl;
    else if (tail) cout << 2 << endl;
    else cout << 3 << endl;
    return 0;
}
