// 問題: https://atcoder.jp/contests/abs/tasks/abc083_b
// 解説: https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

#define CASE 1

#if CASE == 0
// 素直に１桁ずつ処理する
int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    long long total = 0;

    for (int n = 1; n<=N; n++) {
        int sum = n/10000 + (n%10000)/1000 + (n%1000)/100 + (n%100)/10 + (n%10);
        if (A<=sum && sum<=B) total += n;
    }

    cout << total << endl;
    return 0;
}
#endif

#if CASE == 1
// 文字として足し合わせる
int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    long long total = 0;
    for (int n=1; n<=N; n++) {
        string s = to_string(n);
        int sum = 0;
        for (int i=0; i<s.length(); i++) {
            sum += (char)s[i] - (char)'0';
        }
        if (A<=sum && sum<=B) total += n;
    }

    cout << total << endl;
    return 0;
}
#endif
