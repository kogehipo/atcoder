// 問題 https://atcoder.jp/contests/abs/tasks/abc088_b
// 解説 https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

#define CASE 1

#if CASE == 0
// 配列を使った
int main()
{
    int N;
    int a[110];
    int alice = 0, bob = 0;

    cin >> N;
    rep(i, 0, N) cin >> a[i];

    sort(a, a+N, greater<int>());

    rep(i, 0, N) {
        if (i%2) bob += a[i];
        else     alice += a[i];
    }

    cout << alice - bob << endl;

    return 0;
}
#endif

#if CASE == 1
// vectorを使った
int main()
{
    int N;
    cin >> N;

    vector<int> a;
    rep(i, 0, N) {
        int n;
        cin >> n;
        a.push_back(n);
    }
    sort(a.begin(), a.end(), greater<int>());

    int alice = 0, bob = 0;
    rep(i, 0, N) {
        if (i%2) bob += a[i];
        else     alice += a[i];
    }

    cout << alice - bob << endl;

    return 0;
}
#endif
