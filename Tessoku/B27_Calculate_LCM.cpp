#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_o
// 解説 

// 最小公倍数LCM
long long getLCM(int x, int y)
{
    int g = __gcd(x, y);
    return (long long)x / g * y;
}


int main()
{
    int A, B;
    cin >> A >> B;
    cout << getLCM(A, B) << endl;
    return 0;
}
