#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 
// 解説 


int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    int t = 0, a = 0;

    rep(i, N) {
        if      (S[i] == 'T') t++;
        else if (S[i] == 'A') a++;
    }

    if      (t < a) cout << 'A' << endl;
    else if (t > a) cout << 'T' << endl;
    else {
        if (S[N-1] == 'T') cout << 'A' << endl;
        else               cout << 'T' << endl;
    }
    return 0;
}
