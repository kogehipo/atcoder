#include <bits/stdc++.h>
using namespace std;

int main()
{
    // サンプル１
    cout << "Hello, C++\n";
    cout << "Hello, C++" << endl;  // "\n"の代わりにendlでも良い

    cout << "bool   = " << sizeof(bool)   << endl;
    cout << "char   = " << sizeof(char)   << endl;
    cout << "int    = " << sizeof(int)    << endl;
    cout << "long   = " << sizeof(long)   << endl;
    cout << "float  = " << sizeof(float)  << endl;
    cout << "double = " << sizeof(double) << endl;

    // サンプル２
    int a;
    a = 10 + 20;
    cout << "a=" << a << "\n";

    // サンプル3
    int data;
    //char str[80];
    string str;     // C++なのでstring型を使う
    cout << "数字を入力: ";
    cin >> data;
    cout << "2倍すると " << data*2 << "\n";
    cout << "文字列を入力: ";
    cin >> str;
    cout << "受け取った文字列= " << str << "\n";

    return 0;
}
