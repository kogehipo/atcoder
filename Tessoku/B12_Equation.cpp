#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ck
// 解説 

double f(double x)
{
    return (x*x + 1) * x;
}

int main()
{
    int N;
    cin >> N;

    double L = 0.5;
    double R = 100;
    double x;

    while (1)
    {
        x = (L+R)/2;
        double y; 
        if ((y = f(x)) < N) {
            if (N - y < 0.0001) break;
            L = x;
        }
        else {
            if (y - N < 0.0001) break;
            R = x;
        }
    }
    cout << x << endl;
    return 0;
}
