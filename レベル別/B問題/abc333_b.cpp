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
    string S, T;
    cin >> S >> T;
    int s1 = min((int)(S[0]-'A'), (int)(S[1]-'A'));
    int s2 = max((int)(S[0]-'A'), (int)(S[1]-'A'));
    int t1 = min((int)(T[0]-'A'), (int)(T[1]-'A'));
    int t2 = max((int)(T[0]-'A'), (int)(T[1]-'A'));

    int a = s2-s1;
    if (a == 4) a = 1;
    else if (a == 3) a = 2;
    int b = t2-t1;
    if (b == 4) b = 1;
    else if (b == 3) b = 2;

    if (a == b) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
