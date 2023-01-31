#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)


//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_o
// 解説 


int main()
{
    int N;
    cin >> N;

    vector<int> A;
    rep(i, N) { int a; cin >> a; A.push_back(a); }

    // AのコピーBを作りソートする
    vector<int> B = A;
    sort(B.begin(), B.end());

    int v = 1, prev = B[0];
    map<int, int> mp;
    mp[prev] = v;

    rep(i, N) {
        if (prev == B[i]) continue;  // 同じ値は無視する
        mp[B[i]] = ++v;     // 異なる値には連番を振る
        prev = B[i];        // 前の値を記憶する
    }

    // Aの値を連番に置き換え、出力する
    rep(i, N) cout << mp[A[i]] << ' ';
    cout << endl;

    return 0;
}
