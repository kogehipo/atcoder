#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc291/tasks/abc291_c
// 解説 

#define x first
#define y second

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    set<pair<int,int>> history;  // 訪れた座標(x,y)の履歴
    pair<int,int> p;  // 現在の座標(x,y)
    p.x = 0;
    p.y = 0;
    history.insert(p);  // 最初の履歴

    rep(i, N){
        if      (S[i] == 'R') p.x++;
        else if (S[i] == 'L') p.x--;
        else if (S[i] == 'U') p.y++;
        else if (S[i] == 'D') p.y--;
        if (history.find(p) != history.end()) {
            cout << "Yes" << endl;
            return 0;
        }
        history.insert(p);
    }
    cout << "No" << endl;
    return 0;
}
