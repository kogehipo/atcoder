// 1からNまでの和を求めなさい。
// Nは標準入力から与えられるものとする。

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)

// ｎまでの和を求める
long long get_sum(long long n)
{
    if (n <= 0LL) return 0LL;  // 例外処理も兼ねる
    if (n == 1LL) return 1LL;
    return n + get_sum(n-1);
}

int main()
{
    int N;
    cin >> N;

    cout << get_sum((long long)N) << endl;
    return 0;

#if 0
    long long sum = 0;
    for (int i=0; i<=N; i++) sum += i;
    cout << sum << endl;
    return 0;
#endif

#if 0
    long long sum = 0;
    int i = N;
    do {
        sum += i;
    } while (0 < --i);
    cout << sum << endl;
    return 0;
#endif

}
