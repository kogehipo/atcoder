#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int,int>;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc292/tasks/abc292_d
// 解説 ACLに含まれるdsu（Union Find）を使うと良い。
//     https://atcoder.github.io/ac-library/production/document_en/dsu.html

int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> es;  // pairの配列
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--; // ０始まりで扱う
        //es.push_back(P(a,b));
        es.emplace_back(a,b);
    }

    dsu uf(n);
    for (auto [a,b] : es) uf.merge(a,b);
    vector<int> numV(n), numE(n); // 頂点と辺の数
    rep(v,n) numV[uf.leader(v)]++;
    for (auto [a,b] : es) numE[uf.leader(a)]++;

    rep(i,n) if numV[i]) {
        if (numV[i] != numE[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
