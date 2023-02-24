#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_aq
// 解説 

// 数numを2進数文字列に変換
string to_binary_string(long long num, int bit_size)
{
    string ans;
    while (num) {
        if (num%2) ans += "1";
        else       ans += "0";
        num /= 2;
        bit_size--;
    }
    while (bit_size) {
        ans += "0";
        bit_size--;
    }
    // 下の桁から処理したので反転する必要がある
    //reverse(ans.begin(), ans.end());  // 逆順で出力する
    return ans;
}

// aのb乗をmで割った余り
int Power(int a, int b, int m)
{
    string s = to_bunary_string(b, 0);
    ll tmp = 1;

    for (char x : s) {
        tmp = tmp * tmp;

        ans = ans * a;
        if (m < ans) ans %= m;
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
