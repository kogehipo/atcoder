#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int a,b,c; cin >>a>>b>>c;
    if (a == b && b == c) {
        cout << 1 << endl;
        return 0;
    } else if (a != b && b != c && c != a) {
        cout << 3 << endl;
        return 0;

    }
    cout << 2 << endl;
    return 0;
}
