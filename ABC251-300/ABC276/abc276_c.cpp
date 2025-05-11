#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))

int main()
{
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i, N) cin >> P[i];

    vector<int> x;

    for (int i=N-1; i>0; i--) {
        x.push_back(P[i]);
        if (P[i-1] < P[i]) continue;
        // x[]の中で、P[i-1]よりも小さく、最大のものを探す（無いかもしれない）
        sort(all(x));
        auto itr = lower_bound(all(x), P[i-1]);  // イテレータが返される
        if (itr == x.begin()) continue;
//cout << "Found: " << i-1 << ' ' << P[i-1] << ' ' << *(itr-1) << endl;
        int bak = P[i-1];
        P[i-1] = *(itr-1);
        *(itr-1) = bak;
        sort(rall(x));
        range(j, 0, i-1) cout << P[j] << " ";
        rep(j, x.size()) cout << x[j] << " ";
        cout << endl;
        return 0;
    }
    return 0;
}
