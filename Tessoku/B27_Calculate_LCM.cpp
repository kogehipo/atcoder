#include <bits/stdc++.h>
using namespace std;

//#define TEST

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_o
// 解説 

// 最小公倍数LCM
long long getLCM(int x, int y)
{
    int g = __gcd(x, y);
    return (long long)x / g * y;
}

#ifndef TEST
int main()
{
    int A, B;
    cin >> A >> B;
    cout << getLCM(A, B) << endl;
    return 0;
}

#else
// chatGPTが作ったテストコード

// getLCM関数のテスト
void test_getLCM()
{
    // 最小公倍数を求めるためのテストケースを定義する
    int a = 1, b = 2, expected = 2;
    int result = getLCM(a, b);
    assert(result == expected);

    a = 4, b = 6, expected = 12;
    result = getLCM(a, b);
    assert(result == expected);

    a = 10, b = 15, expected = 30;
    result = getLCM(a, b);
    assert(result == expected);
}

int main()
{
    test_getLCM();
    cout << "All tests passed" << endl;
    return 0;
}
#endif