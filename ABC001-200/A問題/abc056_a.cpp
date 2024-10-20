#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    char a, b; cin >> a >> b;
    if (a == 'H' && b == 'H' ||
        a == 'D' && b == 'D') cout << 'H' << endl;
    else cout << 'D' << endl;
    return 0;
}
