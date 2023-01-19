// 解説 文字列の扱い方

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main()
{
    char c[] = "abcd";
    cout << "char data = " << c << endl;
    cout << "size = " << sizeof(c) << endl;  // '\0'もデータの一部
    rep(i, 0, sizeof(c)) {
        cout << c[i] << " : " << (int)c[i] << endl;
    }

    // charへのポインタ
    char *p = c;
    while (*p) cout << *p++ << endl;

    // char配列のコピー
    char d[10];
    strcpy(d, c);
    cout << "copied char = " << d << endl;

    string s = "abcd";
    cout << "string data = " << s << endl;
    cout << "size = " << s.size() << endl;
    rep(i, 0, s.size()) {
        cout << s[i] << " : "
            << dec << (int)s[i] << " : "
            << hex << (int)s[i] << endl;
    }

    // at()でアクセス
    rep(i, 0, s.size()) {
        cout << s.at(i) << endl;
    }
    // 範囲外にアクセスすると例外発生
    //cout << s.at(5) << endl;

    // stringの代入
    string t = s;
    cout << "copied string = " << t << endl;

    // 先頭と末尾の文字
    cout << "front=" << s.front() << " back=" << s.back() << endl;

    // 反転
    reverse(s.begin(), s.end());
    cout << "反転文字列 " << s << endl;


    // 1文字づつ受け取る
    char x;
    while (1) {
        x = getchar();
        if (x == '\0' || x == '\n') break;
        cout << x;
    }
    cout << endl;
}
