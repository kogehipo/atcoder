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
    char S[103];
    cin >> S;

    char c1 = ' ', c2 = ' ';
    int n1, n2;
    char ans = 0;

    int i = 0;
    while (S[i] != '\0') {
        if (c1 == ' ') {
            c1 = S[i]; 
            n1 = i;
        } else if (S[i] != c1 && c2 == ' ') {
            c2 = S[i];
            n2 = i;
        } else if (S[i] == c1) {
            ans = 2;
        } else if (S[i] == c2) {
            ans = 1;
        }
        if (ans == 1 && c1 != ' ') {
            cout << n1+1 << endl;
            return 0;
        } else if (ans == 2 && c2 != ' ') {
            cout << n2+1 << endl;
            return 0;
        }
        i++;
    }
    return 0;
}
