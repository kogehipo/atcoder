#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_aq
// 解説 

// aのb乗をmで割った余り
int Power(int a, int b, int m)
{
    long long ans = 1;
    long long divider = a;
    unsigned int mask = 0x1;
    // べき乗する数bを2進で1bitづつ見ていく
    for (int i=0; i<31; i++) {
        if (b & mask) ans = (ans * divider) % m;
        divider = divider * divider;  // aの2乗、4乗、16乗... と変化する
        divider = divider % m;  // そのままだと大きくなるのでmodしておく
        mask = mask << 1;  // 左隣のbitへ
    }
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << Power(a, b, 1000000007) << endl;
    return 0;
}