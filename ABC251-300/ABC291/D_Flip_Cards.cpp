#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc291/tasks/abc291_d
// 解説 模範解答ではDPを使っているが考え方は同じ

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(n, N) cin >> A[n] >> B[n];

    // i番目に表Aを選んだ場合の、取りうる選び方をcaseAとする。同様に、
    // i番目に表Bを選んだ場合の、取りうる選び方をcaseBとする。
    // 全体の取りうる選び方はcaseA+caseBとなる。
    ll caseA = 1, caseB = 1;  // 最初のカードは「Aを選ぶ」の1通り。Bも同様。
    for (int i=1; i<N; i++) {  // 2枚目以降のカードを精査する
        ll tmpA, tmpB;
        tmpA = caseA; tmpB = caseB;

        if      (A[i] != A[i-1] && A[i] != B[i-1]) tmpA = caseA+caseB; 
        else if (A[i] == A[i-1] && A[i] == B[i-1]) tmpA = 0;
        else if (A[i] == A[i-1])                   tmpA = caseB;
        else if (A[i] == B[i-1])                   tmpA = caseA;

        if      (B[i] != A[i-1] && B[i] != B[i-1]) tmpB = caseA+caseB;
        else if (B[i] == A[i-1] && B[i] == B[i-1]) tmpB = 0;
        else if (B[i] == A[i-1])                   tmpB = caseB;
        else if (B[i] == B[i-1])                   tmpB = caseA;

        caseA = tmpA % 998244353;
        caseB = tmpB % 998244353;
    }
    cout << (caseA + caseB) % 998244353 << endl;
    return 0;
}
