#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N;
    cin >> N;

    map<string, int> mp;
    rep(i, N) {
        string S;
        cin >> S;
        mp[S]++;
    }

    string ans = "";
    int max = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (max < itr->second) {
            max = itr->second;
            ans = itr->first;
        }
    }

    cout << ans << endl;
    return 0;
}
