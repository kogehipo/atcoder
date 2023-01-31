#include <bits/stdc++.h>
using namespace std;

#define N 10

// 再帰関数でnまでの和を求める
long long get_sum(int n)
{
    if (n <= 0) return 0LL;  // 負の値への例外処理も兼ねる
    if (n == 1) return 1LL;
    return (long long)n + get_sum(n-1);
}

// 再帰関数でnの階乗を求める
long long get_kaijo(int n) {
    if (n<=0) return (long long)0;
    if (n==1) return (long long)1;
    if (n==2) return (long long)2;
    return (long long)n * get_kaijo(n-1);
}

int main()
{
    cout << N << " の累積和は " << get_sum(N) << endl;
    cout << N << " の階乗は " << get_kaijo(N) << endl;
    printf("%d の階乗は %ld\n", N, get_kaijo(N));
    return 0;
}
