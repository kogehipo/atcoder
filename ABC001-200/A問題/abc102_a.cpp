#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

#define abs(a,b) ((a)-(b)>0?(a-b):(b-a))

int main()
{
    int N;
    cin >>N;
    if (N%2 == 0) cout << N << endl;
    else cout << 2*N << endl;
    return 0;
}
