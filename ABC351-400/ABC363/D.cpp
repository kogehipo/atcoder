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
    ll N; cin >>N;
    if (N == 1) { cout << 0 << endl; return 0; }
    int len = 1;  // 答えの桁数
    ll gsize = 9; // グループのサイズ
    ll n = 2;  // そのグループ先頭が何番目か
    ll x = 1;  // グループ先頭のID
    while(1) {
        if (n+gsize*2 <= N) {
            len += 2;
            n += gsize*2;
            x *= 10;
            gsize *= 10;
            continue;
        }
        else if (n+gsize <= N) {
            len += 1;
            n += gsize;
            break;
        }
        else {
            break;
        }
    }

    //cout << "len=" << len << endl;  // 答えの桁数
    //cout << "gsize=" << gsize << endl; // グループのサイズ
    //cout << "n=" << n << endl;  // そのグループ先頭が何番目か
    //cout << "x=" << x << endl;  // グループ先頭のID

    // 答えの桁数がlenで確定、その中でN番目を探せば良い
    // そのグループの中で何番目か(0始まり)
    ll k = N - n;
    ll mae = x + k;
    string S = to_string(mae);
    cout << S;
    reverse(S.begin(), S.end());
    int i = 0;
    if (len%2 == 1) i = 1; 
    for (; i<S.size(); i++) {
        cout << S[i];
    }
    cout << endl;
    return 0;
}
