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
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    rep(n, N) cin >> A[n];

    sort(A.begin(), A.end());

    int ans = 0;

    for (int n=0; n<N; n++) {
        auto l = lower_bound(A.begin(), A.end(), A[n]);
        auto r = lower_bound(A.begin(), A.end(), A[n]+M);
        //cout << r - l << endl;
        if (ans < r-l) ans = r-l;
    }

    cout << ans << endl;
    return 0;
}
