#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool ok(char s, char t)
{
    if (s == t) return true;
    if (s == '@' && (t=='a' || t=='t' || t=='c' || t=='o' || t=='d' || t=='e' || t=='r') ) return true;
    if (t == '@' && (s=='a' || s=='t' || s=='c' || s=='o' || s=='d' || s=='e' || s=='r') ) return true;
    return false;
}

int main()
{
    string S, T;
    cin >> S >> T;

    rep(i, S.size()) {
        char s = S[i];
        char t = T[i];
        if ( ok(S[i], T[i]) ) continue;
        else {
            cout << "You will lose" << endl;
            return 0;
        }
    }
    cout << "You can win" << endl;
    return 0;
}
