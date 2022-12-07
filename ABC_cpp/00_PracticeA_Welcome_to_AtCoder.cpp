// 問題 https://atcoder.jp/contests/abs/tasks/practice_1
// 解説 https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

#if 0
int main()
{
    int a, b, c;
    string s;
    cin >> a >> b >> c;
    cin >> s;
    cout << a+b+c << ' ' << s << endl;
    return 0;
}
#endif

// あえてpush/pop使ってみた。
int main()
{
    int a;
    string s;
    stack<int> test;

    rep(i, 0, 3) { cin >> a; test.push(a); }
    cin >> s;
    a = 0;
    rep(i, 0, 3) { a += test.top(); test.pop(); }
    cout << a << ' ' << s << endl;
    return 0;
}

#if 0
// C言語風に書いてみた。
int main()
{
    int a, b, c;
    char s[110];
    scanf("%d\n%d %d\n%s", &a, &b, &c, s);
    printf("%d %s\n", a+b+c, s);
    return 0;
}
#endif