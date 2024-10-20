#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string X;
    cin >> X;

    rep(i, X.size()) {
        if (X[i] == 'c' && X[i+1] == 'h') {
            i++;
            continue;
        }
        if (X[i] == 'o' || X[i] == 'k' || X[i] == 'u') {
            continue;
        }
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}
