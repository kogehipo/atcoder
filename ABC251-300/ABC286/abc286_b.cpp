#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const unsigned long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N; cin >> N;
    string S; cin >> S;
    rep(i,N) {
        cout << S[i];
        if (i < N-1 && S[i] == 'n' && S[i+1] == 'a') cout << 'y';
    }
    cout << endl;
    return 0;
}
