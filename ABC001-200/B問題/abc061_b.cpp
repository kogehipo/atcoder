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

using Graph = vector<vector<int>>;

int main()
{
    int N,M; cin >>N>>M;
    Graph G(N+1);
    rep(i,M) {
        int a,b; cin >>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    range(i,1,N) cout << G[i].size() << endl;
    return 0;
}
