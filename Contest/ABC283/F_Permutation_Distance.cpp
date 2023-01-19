#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc283/tasks/abc283_f
// 解説 これだとTLEする！！
 
 
int main()
{
    // 入力
    int N; cin >> N;
    int P[N];
    rep(i, 0, N) cin >> P[i];
 
    rep(i, 0, N) {
        ll min_val = LINF;
        rep(j, 0, N) {
            if (i == j) continue;
            ll D = abs(P[i]-P[j]) + abs(i-j);
            //cout << "i=" << i << " j=" << j << " D=" << D << endl;
            min_val = min(min_val, D); 
        }
        if (i != 0) cout << ' ';
        cout << min_val;
    }
    cout << endl;
    return 0;
}
