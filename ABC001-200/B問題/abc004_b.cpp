#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    char C[4][4];
    rep(i, 4) rep(j, 4) cin >> C[i][j];

    rep(i, 4) {
        rep(j, 4) {
            if (j != 0) cout << ' ';
            cout << C[3-i][3-j];
        }
        cout << endl;
    }
    return 0;
}
