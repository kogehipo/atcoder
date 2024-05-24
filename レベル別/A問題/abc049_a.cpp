#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    char a; cin >>a;
    if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o') {
        cout << "vowel" << endl;
        return 0;
    }
    cout << "consonant" << endl;
    return 0;
}
