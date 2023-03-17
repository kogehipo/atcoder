#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_o
// 解説 

// 最大公約数GCD
/*
int getGCD(int x, int y)
{
    while (1<=x && 1<=y) {
        if (x < y) y = y % x;
        else       x = x % y;
    }
    if (x != 0) return x;
    return y;
}
*/
int getGCD(int x, int y)
{
    if (y == 0) return x;
    return getGCD(y, x%y);
}

int main()
{
    int A, B;
    cin >> A >> B;
    //cout << getGCD(A, B) << endl;
    cout << __gcd(A, B) << endl;    // __gcdはC++17から追加された関数
    return 0;
}
