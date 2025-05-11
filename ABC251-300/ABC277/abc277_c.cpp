#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) begin(a), end(a)

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    map<int,int> floor2node;  // はしごの階/頂点番号
    map<int,int> node2floor;  // 頂点番号/はしごの階
    int node = 0;  // 頂点番号（dsuのインデックス）
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        A[i] = a-1;
        if (floor2node.find(a-1) == floor2node.end()) {
            floor2node[a-1] = node;
            node2floor[node] = a-1;
            node++;
        }
        B[i] = b-1;
        if (floor2node.find(b-1) == floor2node.end()) {
            floor2node[b-1] = node;
            node2floor[node] = b-1;
            node++;
        }
    }
/*
    cout << "floor->node: ";
    for (const auto& item : floor2node) cout << item.first << "->" << item.second << " ";
    cout << endl;
    cout << "node->floor: ";
    for (const auto& item : node2floor) cout << item.first << "->" << item.second << " ";
    cout << endl;
*/

    // 梯子のある階でUnionFindする
    dsu d(node2floor.size());
    rep(i, N) {
        d.merge(floor2node[A[i]], floor2node[B[i]]);
    }

    int ans = 0;
    // 各連結要素でループ
    for (auto& g : d.groups()) {
        bool connectedTo1stFloor = false;
        int maxFloor = 0;
        rep(i, g.size()) {
            int floor = node2floor[g[i]];
            if (floor == 0) connectedTo1stFloor = true;
            else maxFloor = max(maxFloor, floor);
        }
        if (connectedTo1stFloor) ans = max(ans, maxFloor);
    }
    cout << ans+1 << endl;
    return 0;
}
