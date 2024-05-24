#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S; cin >> S;
    vector<int> ans(6, 0);
    rep(i, S.size()) {
        ans[S[i]-'A']++;
    }
    rep(i, 6) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
