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
    rep(i, T.size()) T[i] = T[i] + 'a' - 'A'; 
    //sort(all(S));
    //sort(all(T));

    //cout << S << endl;
    //cout << T << endl;

    bool f1 = false;
    bool f2 = false;
    bool f3 = false;
    rep(i, S.size()) {
        if (!f1) {
            if (S[i] == T[0]) f1 = true;
            continue;
        }
        else if (!f2) {
            if (S[i] == T[1]) f2 = true;
            continue;
        }
        else if (!f3) {
            if (S[i] == T[2]) {
                f3 = true;
                break;
            }
            continue;
        }
//cout << f1 << f2 << f3 << endl;
    }


    if (f3) cout << "Yes" << endl;
    else if (f2 && T[2] == 'x') cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
