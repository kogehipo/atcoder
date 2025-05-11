#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    string S; cin >>S;
    map<char,pair<int,int>> mp;
    mp['L'] = make_pair(-1, 0);
    mp['R'] = make_pair( 1, 0);
    mp['U'] = make_pair( 0, 1);
    mp['D'] = make_pair( 0, -1);
    int x = 0, y = 0;
    int lost = 0;
    rep(i, S.size()) {
        if (S[i] == '?') {
            lost++;
            continue;
        }
        x += mp[S[i]].first;
        y += mp[S[i]].second;
    }
    int ans = abs(x) + abs(y);
    int T; cin >>T;
    if (T == 1) {
        cout << ans + lost << endl;
        return 0;
    } else {
        if (ans >= lost) {
            cout << ans - lost << endl;
            return 0;
        } else {
            cout << (lost - ans) % 2 << endl;
            return 0;
        }
    }
    return 0;
}
