#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc283/tasks/abc283_d
// 解説 


int main()
{
    stack<char> s; // 読み込んだ文字列をスタックに格納
    set<char> box;  // ボールを入れる箱

    while(1) {
        // 1文字読む
        char c;
        c = getchar();
        if (c == '\0' || c == '\n') break;

        // 左括弧ならスタックに積む
        if (c == '(') {
            s.push(c);
        }

        // 右括弧なら直前の左括弧までさかのぼって調べる
        else if (c == ')') {
            while (s.top() != '(') {  // 左括弧が見つかったら終わり
                box.erase(s.top());   // 文字なら箱から出して
                s.pop();              // スタックから出す
            }
            s.pop();  // 左括弧もスタックから出す
        }

        // 文字なら箱に入れて、スタックに積む
        else {
            // その文字がすでに箱にあったら気絶する
            if (box.find(c) != box.end()) {
                cout << "No" << endl;
                return 0;
            }
            box.insert(c); // その文字を箱に入れて
            s.push(c);     // スタックに積む
        }
    }

    cout << "Yes" << endl;

    return 0;
}
