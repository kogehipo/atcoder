#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Card { int strength, cost, position; };
bool operator<(const Card &c1, const Card &c2) { return c1.strength < c2.strength; }

int main()
{
    int N;
    cin >> N;
    vector<Card> C(N);
    rep(i, N) {
        cin >> C[i].strength;  // 強さ
        cin >> C[i].cost;      // コスト
        C[i].position = i+1;   // 元の位置
    }
    sort(rall(C));
    //rep(i, N) cout << C[i].strength << ' ' << C[i].cost << endl;
    vector<int> ans;
    ans.push_back(C[0].position);  // 最後のカードは必ず選ぶ
    int biggest_cost = C[0].cost;
    range(i, 1, N-1) {
        if (biggest_cost > C[i].cost) {
            ans.push_back(C[i].position);
            biggest_cost = C[i].cost;
        }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
