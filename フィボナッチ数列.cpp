#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 
// 解説 

int func_add(int a, int b)
{
    int c = a + b;
    return c;
}

int func_acc(int a)
{
    int c = 0;
    for (int i=1; i<=a; i++) c += i;
    return c;
}

int func_acc2(int a)
{
    cout << "a=" << a << endl;

    int value;

    if (a == 1) {
        value = 1;
    } else {
        value = func_acc2(a-1) + a;
    }

    cout << "value=" << value << endl;
    return value;
}


int func_mul(int a, int b)
{
    int c = a * b;
    return c;
}

int func_kaijo(int a)
{
    int c = 1;
    for (int i=1; i<=a; i++) c *= i;
    return c;
}

int func_kaijo2(int a)
{
    if (a == 1) {
        return 1;
    } else {
        return func_kaijo2(a-1) * a;
    }
}

ll fibo(ll a)
{
    if (a == 0) return 0;
    if (a == 1) return 1;

    ll a_2 = 0;
    ll a_1 = 1;
    ll result = 1;
    for (int i=2; i<=a; i++) {
        result = a_1 + a_2;
        a_2 = a_1;
        a_1 = result;
    }
    return result;
}

ll fibo2(ll a)
{
    if      (a == 0) return 0;
    else if (a == 1) return 1;
    else return fibo2(a-1) + fibo2(a-2);
}

ll fibo3(ll a)
{
    static vector<ll> memo(10000, -1);
    ll x;

    if (a == 0) {
        memo[0] = 0;
        return 0;
    }
    else if (a == 1) {
        memo[1] = 1;
        return 1;
    }
    else {
        ll a_2 = (memo[a-2] != -1) ? memo[a-2] : fibo3(a-2);
        ll a_1 = (memo[a-1] != -1) ? memo[a-1] : fibo3(a-1);
        x = a_1  + a_2;
        memo[a] = x;
        return x;
    }
}

int main()
{
    ll result;
    vector<int> A = {10, 5, 30, 25, 33, 40};

    for (auto a : A) {
        result = fibo3(a);
        cout << result << endl;
    }

/*
    result = fibo(30);
    cout << result << endl;
    result = fibo2(30);
    cout << result << endl;
    result = fibo3(30);
    cout << result << endl;
*/

/*
    result = fibo2(1);
    cout << result << endl;
    result = fibo2(2);
    cout << result << endl;
    result = fibo2(3);
    cout << result << endl;
    result = fibo2(4);
    cout << result << endl;
    result = fibo2(5);
    cout << result << endl;
    result = fibo2(6);
    cout << result << endl;

    result = func_kaijo2(4);
    cout << result << endl;

    result = func_acc2(10);
    cout << result << endl;

    int result = func_add(5, 3);
    cout << result << endl;

    result = func_acc(10);
    cout << result << endl;

    result = func_mul(5, 3);
    cout << result << endl;

    result = func_kaijo(4);
    cout << result << endl;
*/
    return 0;
}
