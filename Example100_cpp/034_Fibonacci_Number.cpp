// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A&lang=ja

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#if 0
// 再帰関数を使う方法。これは時間オーバーする
// 理由： fibo(n)を求めるにはfibo(n-1)とfibo(n-2)を計算するが、
//       fibo(n-2)はfibo(n-1)を求めるときに既に計算済み。
long long fibo(long long n)
{
    if (n == 0 || n == 1) return 1;
    return fibo(n-1) + fibo(n-2);
}

int main()
{
    long long n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}
#endif

#if 0
// メモ化再帰による実装
// 一度計算した結果はここに格納しておく
long long f[44] = {0LL};

long long fibo(long long n)
{
    if (n == 0 || n == 1) {
        f[n] = 1;
        return 1;
    }

    if (f[n-2] == 0) f[n-2] = fibo(n-2);
    if (f[n-1] == 0) f[n-1] = fibo(n-1);

    f[n] = f[n-2] + f[n-1];
    return f[n];
}

int main()
{
    long long n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}
#endif

// 普通にfor分で実装。これが一番早い。
int main()
{
    long long pro[50] = {0LL};
    int n;
    cin >> n;
    pro[0] = 1LL;
    pro[1] = 1LL;
    for (int i=2; i<=n; i++) {
        pro[i] = pro[i-1] + pro[i-2];
    }
    cout << pro[n] << endl;
    return 0;
}
