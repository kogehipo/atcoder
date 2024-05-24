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
    int N;
    cin >> N;
    if (N == 100) cout << "Perfect" << endl; 
    else if (90 <= N) cout << "Great" << endl; 
    else if (60 <= N) cout << "Good" << endl; 
    else cout << "Bad" << endl; 
    return 0;
}
