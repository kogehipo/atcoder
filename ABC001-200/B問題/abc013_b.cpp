#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int a, b;
    cin >> a >> b;
    int n = abs(a - b);
    if (n <= 5) {
        cout << n << endl;
        return 0;
    }
    cout << 10-n << endl;
    return 0;
}
