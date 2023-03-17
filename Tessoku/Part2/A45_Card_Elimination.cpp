#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_as
// 解説 
// W=0, B=1, R=2 とすると、
// W+W=W  0+0=0
// B+B=R  1+1=2
// R+R=B  2+2=4→1
// W+B=B  0+1=1
// W+R=R  0+2=2
// B+R=W  1+2=3→0

int main()
{
    int N;
    char C;
    cin >> N >> C;
    string A;
    cin >> A;

    int num = 0;
    rep(a, N) {
        if      (A[a] == 'B') num += 1;
        else if (A[a] == 'R') num += 2;
        num %= 3;
    }
    if (C == 'W' && num == 0 ||
        C == 'B' && num == 1 ||
        C == 'R' && num == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
