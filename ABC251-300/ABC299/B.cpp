#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc299/tasks/abc299_b
// 解説 


int main()
{
    int N, T;
    cin >> N >> T;
    vector<int> C(N), R(N);

    rep(n, N) cin >> C[n];
    rep(n, N) cin >> R[n];

    map<int, pair<int, int>> m;
    rep(n, N) {
        auto itr = m.find(C[n]);
        if (itr == m.end()) {
            // まだ誰も色Ｔのカードを出してない
            m[C[n]].first = n+1;
            m[C[n]].second = R[n];
        } else {
            // すでに色Ｔのカードが出されている場合
            if (m[C[n]].second < R[n]) {
                m[C[n]].first = n+1;
                m[C[n]].second = R[n];
            }
        }
    }
/*
    for (const auto& [key, value] : m) {
        cout << key << " : " << value.first << ", " << value.second << endl;
    }
*/
    auto itr = m.find(T);
    if (itr == m.end()) {
        // 色Tを出した人はいない
        cout << m[C[0]].first << endl;
        return 0;
    }
    else {
        // 誰か色Tを出した
        cout << m[T].first << endl;
        return 0;
    }
}
