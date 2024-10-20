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
    cin >> N;

    vector<int> D(N);
    rep(n, N) cin >> D[n];

    int ans = 0;

    for (int i=1; i<=9; i++) {

        int a = i;
        int b = 11*i;

        // 2月2日
        if (a<=N && a<=D[a-1]) ans ++;

        // 2月22日
        if (a<=N && b<=D[a-1]) ans ++;

        // 22月2日
        if (b<=N && a<=D[b-1]) ans ++;

        // 22月22日
        if (b<=N && b<=D[b-1]) ans ++;

    }

    cout << ans << endl;
    return 0;
}
