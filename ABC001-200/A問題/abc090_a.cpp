#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    vector<string> C(3);
    rep(i,3) cin >>C[i];
    rep(i,3) cout <<C[i][i];
    cout << endl;
    return 0;
}
