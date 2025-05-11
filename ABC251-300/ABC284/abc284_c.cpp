#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, M;
    cin >> N >> M;
    dsu d(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        d.merge(u, v);
    }
    cout << d.groups().size() << endl;
    return 0;
}
