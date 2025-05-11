// 問題 https://atcoder.jp/contests/abc095/tasks/arc096_a

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    // A,B,Cを購入する枚数とその金額
    int a, b, c, cost;
    int min_a, min_b, min_c;

    cost = INF;
    for (int c=0; c<=max(X,Y)*2; c++) {
        a = max(0, X - c/2);
        b = max(0, Y - c/2);
        int price = a*A + b*B + c*C;
        if (price < cost) {
            cost = price;
            min_a = a;
            min_b = b;
            min_c = c;
        }
    }

    cout << cost << endl;
    //cout << min_a << " " << min_b << " " << min_c << endl;
    return 0;
}
