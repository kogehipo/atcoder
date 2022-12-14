// 解説 スタックとキューの使い方

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main()
{
    stack<int> st;   // スタックを宣言

    st.push(3);        // スタックにデータを積む
    st.push(5);
    st.push(7);

    cout << "Stack size = " << st.size() << endl;  // サイズ

    cout << st.top() << endl;  // スタックの頭
    st.pop();   // スタック削除


    queue<int> qu;   // キューを宣言

    qu.push(3);    // キューに要素追加
    qu.push(5);
    qu.push(7);

    cout << "Queue size = " << qu.size() << endl;  // サイズ

    cout << qu.front() << endl;   // キューの先頭
    qu.pop();   // キューの削除


}
