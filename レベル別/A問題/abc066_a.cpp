#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >>a>>b>>c;
    int ab = a+b;
    int bc = b+c;
    int ca = c+a;
    int ans = min(ab, bc);
    ans = min(ans, ca);
    cout << ans << endl;
    return 0;
}
