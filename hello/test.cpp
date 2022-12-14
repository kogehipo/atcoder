#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main()
{
queue<int> qu;   // キューを宣言

qu.push(3);    // キューに要素追加
qu.push(5);
qu.push(7);

cout << qu.size() << endl;  // サイズ

cout << qu.front() << endl;   // キューの先頭
qu.pop();   // キューの削除


}
