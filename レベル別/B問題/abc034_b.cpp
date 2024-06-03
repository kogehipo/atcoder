#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int n; cin >>n;
    if (n % 2 == 0) cout << n-1 << endl;
    else cout << n+1 << endl;
    return 0;
}
