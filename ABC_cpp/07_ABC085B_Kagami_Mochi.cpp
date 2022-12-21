// 問題 https://atcoder.jp/contests/abs/tasks/abc085_b
// 解説 https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

#define CASE 2

#if CASE == 1
int main()
{
    int N;
    int d[110];

    cin >> N;
    d[0] = 0;
    rep(i, 1, N+1) cin >> d[i];

    sort(d, d+N+1);

    int count = 0;
    rep(i, 1, N+1) {
        if (d[i] != d[i-1]) count++;
        //cout << i << " - " << d[i] << " - " << count << endl;
    }

    cout << count << endl;

    return 0;
}
#endif

#if CASE == 2
// 餅の種類を数えれば良いのでset()を使う
int main()
{
    int N;
    set<int> st;

    cin >> N;
    rep(i, 0, N) {
        int d;
        cin >> d;
        st.insert(d);
    }

    cout << st.size() << endl;

    return 0;
}
#endif
