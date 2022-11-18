/*********************
これはGCC(g++)とclang++の両方で動くサンプル。
$ g++ hello_clang.cpp
$ clang++ hello_clang.cpp

Macでは特別な設定をしなくてもg++コマンドが動きます。
ただし多くの場合、そのg++コマンドはXcodeと一緒に
インストールされるclang++のエイリアスです。
競プロで使われる本物のg++は brew install gcc で
インストールする必要があります。

競プロでよく使う #include <bits/stdc++.h> はMac版のg++には存在しません。
Mac版のコンパイラかどうかは #ifdef __clang_version__ で判定できます。

*********************/

#ifdef __clang_version__   // Mac版g++(clang++)の場合
#include <iostream>
#else                      // その他、競プロ環境の場合
#include <bits/stdc++.h>
#endif
using namespace std;       // 基本、これは常に書く

int main()
{
#ifdef __clang_version__
    cout << __clang_version__ << endl;
#endif

    cout << "Hello, C++" << endl;  // "\n"の代わりにendlでも良い
    return 0;
}
