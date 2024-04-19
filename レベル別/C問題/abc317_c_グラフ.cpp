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

int N, M;
vector<vector<pair<int,int>>> T(12);

ll getCost(int i, ll cost, vector<bool> visited) {
//cout << "(1) " << cost << endl;
    visited[i] = true;
    vector<bool> v = visited;
    ll c = cost;
    rep(j, T[i].size()) {
        if (v[T[i][j].first]) continue;
        c = max(c, getCost(T[i][j].first, cost + T[i][j].second, v));
    }
//cout << "(2) " << c << endl;
    return c;
}

int main()
{
    cin >> N >> M;
    rep(i, M) {
        int from, to, cost;
        cin >> from >> to >> cost;
        T[from].push_back({to, cost});
        T[to].push_back({from, cost});
    }

    ll ans = 0;

    rep(i, N) {
        ll cost = 0;
        vector<bool> visited(12, false);
        ans = max(ans, getCost(i, cost, visited));
    }
    cout << ans << endl;
    return 0;
}
