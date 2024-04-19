#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    string S;
    cin >> S;

    if ('a' <= S[0] && S[0] <= 'z') cout << (char)(S[0] + 'A' - 'a');
    else cout << S[0];

    range(i, 1, S.size()-1) {
        if ('A' <= S[i] && S[i] <= 'Z')  cout << (char)(S[i] + 'a' - 'A');
        else cout << S[i];
    }
    cout << endl;
    return 0;
}
