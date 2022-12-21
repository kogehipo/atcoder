#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 0から9までの数を1行ずつ改行して出力しなさい。
    cout << "0から9までの数を1行ずつ改行して出力しなさい。" << endl;
    for (int i=0; i<10; i++) {
        cout << i << endl;
        //cout << i << '\n';
        //printf("%d\n", i);
    }

    int i=0;
    while (i<10) {
        cout << i++ << endl;
    }

    // 1から10までの数を1行ずつ改行して出力しなさい。
    cout << "1から10までの数を1行ずつ改行して出力しなさい。" << endl;
    for (int i=1; i<=10; i++) {
        cout << i << endl;
    }

    // 10から1までの数を1行ずつ改行して出力しなさい。
    cout << "10から1までの数を1行ずつ改行して出力しなさい。" << endl;
    for (int i=10; 1<=i; --i) {
        cout << i << endl;
    }

    // 1から20までの数で、偶数だけを出力しなさい。
    cout << "1から20までの数で、偶数だけを出力しなさい。" << endl;
    for (int i=1; i<=20; i++) {
        if ((i % 2) == 0) cout << i << endl;
    }

    // 1から20までの数で、3で割り切れない数だけを出力しなさい。
    cout << "1から20までの数で、3で割り切れない数だけを出力しなさい。" << endl;
    for (int i=1; i<=20; i++) {
        if (i % 3) cout << i << endl;
    }

    // 1から20までの数で、3または5で割り切れる数を出力しなさい。
    cout << "1から20までの数で、3または5で割り切れる数を出力しなさい。" << endl;
    for (int i=1; i<=20; i++) {
        if ((i % 3) == 0 || (i % 5) == 0 ) cout << i << endl;
    }

    // a から j までを1文字ずつ改行しながら出力しなさい。
    cout << "a から j までを1文字ずつ改行しながら出力しなさい。" << endl;
    for (char c='a'; c<='j'; c++) {
        cout << c << endl;
    }

    // 文字も数値
    cout << 'a' << endl;
    cout << (int)'a' << endl;
    cout << 'b' << endl;
    cout << (int)'b' << endl;
    cout << 'A' << endl;
    cout << (int)'A' << endl;
    cout << (char)('b' + ('A' - 'a')) << endl; 

    return 0;
}
