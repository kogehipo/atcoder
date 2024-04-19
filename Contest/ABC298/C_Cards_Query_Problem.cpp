#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc298/tasks/abc298_c
// 解説 

int main()
{
    int N, Q;
    cin >> N >> Q;

    // 箱Box[N]に入っているカードをmultisetで持つ
    vector<multiset<int>> Box(N+1);

    // カードを配った箱の番号をsetで持つ
    vector<set<int>> Card(200009);

    rep(q, Q) {  // クエリーを繰り返し
        int query, i, j;
        cin >> query;
        cin >> i;
        if (query == 1) {
            cin >> j;
            Box[j].insert(i);
            Card[i].insert(j);
        } else if (query == 2) {
            //cout << '>';
            int flag = false;  // スペース出力の制御
            for (auto itr=Box[i].begin(); itr!=Box[i].end(); itr++) {
                if (flag) cout << ' ';
                flag = true;
                cout << *itr;
            }
            cout << endl;
        } else if (query == 3) {
            //cout << '>';
            int flag = false;  // スペース出力の制御
            for (auto itr=Card[i].begin(); itr!=Card[i].end(); itr++) {
                if (flag) cout << ' ';
                flag = true;
                cout << *itr;
            }
/*
            // こうするとTLE
            for (int n=1; n<=N; n++) {
                if (Box[n].find(i) != Box[n].end()) {
                    if (flag) cout << ' ';
                    flag = true;
                    cout << n;
                }
            }
*/
            cout << endl;
        }        
    }
    return 0;
}
