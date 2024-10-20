#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int A,B,X;
    cin >>A>>B>>X;
    if (A <= X && X <= A+B) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
