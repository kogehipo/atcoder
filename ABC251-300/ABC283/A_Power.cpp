#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc283/tasks/abc283_a
// 解説 


int main()
{
    ll A, B; cin >> A >> B;
    cout << (long long)pow(A, B) << endl;  // pow()は浮動小数点型なので型変換が必要
    return 0;
}
