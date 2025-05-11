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
    int N;
    string S, T;
    cin >> N >> S >> T;

    rep(i, N) {
        if (S[i] == T[i]) continue;
        if (S[i] == 'l' && T[i] == '1') continue;
        if (S[i] == '1' && T[i] == 'l') continue;
        if (S[i] == 'o' && T[i] == '0') continue;
        if (S[i] == '0' && T[i] == 'o') continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
