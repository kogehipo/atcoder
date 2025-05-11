#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N,M; cin>>N>>M;
    vector<pair<int,int>> RL(N); // Rから対応するLの位置を参照する
    rep(i,N) {
        int L, R;
        cin >> RL[i].second >> RL[i].first;
    }
    sort(RL.begin(), RL.end());

    ll ans = 0;
    int r = 0;
    // すべてのlに対して、rを伸ばせる範囲を探索する。
    range(l,1,M) {
        r = l;
        for (; r<=M; r++) {
            cout << "l=" << l << " r=" << r << endl;
            if (l <= RL[r]) break; // この位置に右点Rがあり、lが対応するLより左
            ans++;
            cout << "Movinr R : ans=" << ans << " {" << l << "," << r << "}" << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

/*
4 10
2 6
3 4
5 8
7 9

*/