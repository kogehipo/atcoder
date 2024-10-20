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
    int A,B,C,K,S,T;
    cin >>A>>B>>C>>K>>S>>T;
    int sum1;
    sum1 = S*A + T*B;
    int sum2 = INF;
    if (S+T >= K) {
        sum2 = S*(A-C) + T*(B-C);
    }
    cout << min(sum1, sum2) << endl;
    return 0;
}
