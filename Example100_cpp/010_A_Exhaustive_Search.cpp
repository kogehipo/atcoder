// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


// p: 整数列へのポインタ(終端は-1)
// m: 足し合わせて作る数
// 戻り値: mを作れたらtrue、作れなかったらfalse
bool check(int *p, int m)
{
    //cout << "*p=" << *p << " m=" << m << endl; // Debug

    // 使える整数がない
    if (*p == -1) return false;

    // 調べている数そのものが出現したらtrue
    if (*p == m) return true;

    // *pを使わない場合、整数列の以降を調べる
    if (check(p+1, m)) return true;  // mが作れたらここでtrue

    // *pを使う場合は、その分を減算して続ける
    m -= *p;
    if (m < 0) return false;  // 作るべき数が負になったらfalse
    return check(p+1, m);
}


int main()
{
    // 数列の長さ:N
    int N;
    cin >> N;

    // 数列を読み込む:A[]
    int A[N+1];
    rep (n, 0, N) cin >> A[n];
    // 数列の終端に、目印として-1をセット
    A[N] = -1;

    // 検査する数字の数:Q
    int Q;
    cin >> Q;

    // Q個の数を順次調べる
    rep (q, 0, Q) {
        // 調べる数:m
        int m;
        cin >> m;
        if (check(A, m)) cout << "yes" << endl;
        else             cout << "no"  << endl;
    }

    return 0;
}
