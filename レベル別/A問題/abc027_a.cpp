#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int A,B,C;
    cin >> A >> B >> C;
    if (A == B) cout << C << endl; 
    else if (A == C) cout << B << endl; 
    else if (B == C) cout << A << endl; 
    return 0;
}
