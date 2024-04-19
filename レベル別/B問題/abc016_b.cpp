#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int add = A+B;
    int sub = A-B;

    if (add == C && sub != C) cout << '+' << endl;
    else if (add != C && sub == C) cout << '-' << endl;
    else if (add == C && sub == C) cout << '?' << endl;
    else cout << '!' << endl;
    return 0;
}
