// 問題 https://atcoder.jp/contests/abc102/tasks/arc100_a
// 解説 https://betrue12.hateblo.jp/entry/2018/07/02/005620

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

int main()
{
    int N;
    cin >> N;
    int A[N];
    rep(i, 0, N) cin >> A[i];

    // A[i]をiだけ調節する
    rep(i, 0, N) A[i] -= i+1;

    // 中央値mを求める
    sort(A, A+N);
    ll m;
    if (N % 2) {  // データ個数が奇数なら真ん中の値
        m = A[(N+1)/2-1];
    }
    else {   // データ個数が偶数なら真ん中２個の平均値
        m = (A[N/2-1] + A[N/2])/2;
    }

    // 中央値との距離の総和
    ll ans = 0;
    rep(i, 0, N) ans += abs(m - A[i]);

    cout << ans << endl;
    return 0;
}
