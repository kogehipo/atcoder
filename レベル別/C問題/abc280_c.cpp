#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    string S, T;
    cin >> S >> T;
    int s, t;

    int i = 0;
    while (S[i] == T[i]) {
        i++;
    }
    cout << i+1 << endl;
    return 0;
}
