#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;
    char memo;
    int cnt;
    int i = 0;
    while(1) {
        if (i == 0) {
            cnt = 1;
            memo = s[0];
        }
        else if (s[i] != memo) {
            cout << memo << cnt;
            cnt = 1;
            memo = s[i];
        } else {
            cnt++;
        }
        if (s[i] == '\0') {
            cout << endl;
            return 0;
        }
        i++;
    }
}
