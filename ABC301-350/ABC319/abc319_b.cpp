#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N; cin>>N;

    range(i,0,N) {
        bool found = false;
        range(yaku,1,9) {
            if (N%yaku != 0) continue;
            if (i % (N/yaku) == 0) {
                cout << yaku;
                found = true;
                break;
            }
        }
        if (!found) cout << "-";
    }
    cout << endl;
    return 0;
}
