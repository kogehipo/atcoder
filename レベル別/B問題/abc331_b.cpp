#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7FFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N,S,M,L;
    cin >>N>>S>>M>>L;
    int ans = INF;
    range(s, 0, N/6+1) {
        range(m, 0, N/8+1) {
            range(l, 0, N/12+1) {
                int sum = s*6 + m*8 + l*12; // 個数
                if (sum < N) continue;
                sum = s*S + m*M + l*L; // 金額
                ans = min(ans, sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
