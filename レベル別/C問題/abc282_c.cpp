#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    bool flg = true;
    rep(i, N) {
        if (S[i] == '"') flg = !flg;
        else if (flg && S[i] == ',') S[i] = '.';
    }
    cout << S << endl;
    return 0;
}
