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
    string S, T;
    cin >> S >> T;

    int s = abs(S[0] - S[1]);
    int t = abs(T[0] - T[1]);
    if (s == 4) s = 1;
    if (t == 4) t = 1;
    if (s == 3) s = 2;
    if (t == 3) t = 2;

    //cout << s << " " << t << endl;

    if (s == t) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}
