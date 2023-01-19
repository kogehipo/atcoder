#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc283/tasks/abc283_c
// 解説 


int main()
{
    char S[100100];
    cin >> S;
    char *p = S;

    int touch = 0;

    do {
        if (*p == '0' && *(p+1) == '0') p += 2;
        else p += 1;
        touch++;
    } while (*p);

    cout << touch << endl;
    return 0;
}
