#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

#define abs(a,b) ((a)-(b)>0?(a-b):(b-a))

int main()
{
    int a,b,c,d;
    cin >>a>>b>>c>>d;
    if (abs(a,c) <= d ||
        (abs(a,b) <= d && abs(b,c) <= d)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
