#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc292/tasks/abc292_b
// 解説 

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> card(N+1, 0);

    rep(q, Q) {
        int jadge, player;  
        cin >> jadge >> player;
        if      (jadge == 1) card[player] += 1;
        else if (jadge == 2) card[player] += 2;
        else if (jadge == 3) {
            if (2 <= card[player]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
