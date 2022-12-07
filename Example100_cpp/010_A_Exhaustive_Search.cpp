// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


// 正数列(終端は-1)を足し合わせてmを作れたらtrueを返す
bool check(int *p, int m)
{
    //cout << "check(" << *p << ", " << m << ")" << endl;  // デバッグ

    while (*p != -1)
    {
        // 調べている数そのものが出現したらtrue
        if (*p == m) return true;

        // *pを選択しない場合、数列の次の数を調べる
        if (check(p+1, m)) return true;

        // *pを選択する場合はその分を減算して続ける
        m -= *p;
        if (m < 0) return false;
        return check(p+1, m);
    }
    return false;
}


int main()
{
    // 数列の長さ:n
    int n;
    cin >> n;

    // 数列を読み込む:A[]
    int A[n+1];
    rep (i, n) cin >> A[i];
    // 数列の終端に、目印として-1をセット
    A[n] = -1;

    // 検査する数字の数:m
    int m;
    cin >> m;

    // m個の数を順次調べる
    rep (i, m) {
        // 調べる数:q
        int q;
        cin >> q;

        if (i != 0) cout << " ";  // ２回め以後は区切りのスペースを入れる
        if (check(A, q)) cout << "yes";
        else             cout << "no";
    }
    cout << endl;

    return 0;
}
