#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc298/tasks/abc298_a
// 解説 

int main()
{
    int N; cin >> N;
    string S; cin >> S;

    bool passed = false;  // 合格判定の面接官がいたか？
    for (int i=0; i<S.size(); i++) {
        if (S[i] == 'x') {  // 不合格判定があったら即刻不合格
            cout << "No" << endl;
            return 0;
        }
        if (S[i] == 'o') passed = true;  // 合格判定あり
    }
    if (passed) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
