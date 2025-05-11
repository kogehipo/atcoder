#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    string S;
    cin >> S;
    int i = 0;
    while (S[i] == 'A') i++;
    while (S[i] == 'B') i++;
    while (S[i] == 'C') i++;
    if (S[i] == '\0') cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
