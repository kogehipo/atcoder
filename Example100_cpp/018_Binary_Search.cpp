// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


// lower_bound() を使ってみた。
// 参考 https://pyteyon.hatenablog.com/entry/2019/02/20/194140
int main()
{
    // 設問で与えられた変数名は煩雑なので置き換えている。
    int Ssize;  // 設問のn
    cin >> Ssize;
    int S[Ssize];
    rep (s, Ssize) cin >> S[s];

    int Tsize;  // 設問のq
    cin >> Tsize;
    int T[Tsize];
    rep (t, Tsize) cin >> T[t];

    // lower_bound()はソート不要
    //sort(S, S+Ssize);

    int count = 0;
    rep (t, Tsize) {
        // lower_bound()は、指定したkey以上の要素の内、
        // 一番左側の要素の位置（最小のインデックス）をイテレータで返す
        int b = *lower_bound(S, S+Ssize, T[t]);
        if (b == T[t]) count++;
    }

    cout << count << endl;
    return 0;
}


#if 0
// binary_search() を使ってみた。
// 参考 https://pyteyon.hatenablog.com/entry/2019/02/20/194140
int main()
{
    // 設問で与えられた変数名は煩雑なので置き換えている。
    int Ssize;  // 設問のn
    cin >> Ssize;
    int S[Ssize];
    rep (s, Ssize) cin >> S[s];

    int Tsize;  // 設問のq
    cin >> Tsize;
    int T[Tsize];
    rep (t, Tsize) cin >> T[t];

    sort(S, S+Ssize);

    int count = 0;
    rep (t, Tsize) {
        if (binary_search(S, S+Ssize, T[t])) count++;
    }

    cout << count << endl;
    return 0;
}
#endif


#if 0
// 何も考えずsort()を使って解いた
int main()
{
    // 設問で与えられた変数名は煩雑なので置き換えている。
    int Ssize;  // 設問のn
    cin >> Ssize;
    int S[Ssize];
    rep (s, Ssize) cin >> S[s];

    int Tsize;  // 設問のq
    cin >> Tsize;
    int T[Tsize];
    rep (t, Tsize) cin >> T[t];

    sort(S, S+Ssize);
    sort(T, T+Tsize);

    int s, t, count;
    s = t = count = 0;
    while (s < Ssize && t < Tsize) {
        if (S[s] < T[t]) {
            s++;
        }
        else if (T[t] < S[s]) {
            t++;
        }
        else {
            count++;
            s++;
            t++;
        }
    }
    cout << count << endl;
    return 0;
}
#endif
