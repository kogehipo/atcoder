// 解説 autoの使い方
//     https://prettysoft.hatenablog.com/entry/20101113/1418577983

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main()
{
    vector<int> num = {10, 20};
    string str = "ABC";


    cout << "auto ---" << endl;
    for (auto n : num) {   // nはnum要素のコピー
        n += 5;            // nを変更しても元の値は変わらない
        cout << n << endl;
    }
    for (auto n : num) cout << n << endl;  // もう一度見ても元のまま

    cout << "auto ---" << endl;
    for (auto s : str) {   // sはstr要素のコピー
        s += 2;            // sを変更しても元の値は変わらない
        cout << s << endl;
    }
    cout << str << endl;  // もう一度見ても元のまま


    cout << "auto& ---" << endl;
    for (auto& n : num) {   // nはnum要素の参照
        n += 5;             // nを変更すると元データも変わる
        cout << n << endl;
    }
    for (auto n : num) cout << n << endl;  // 元データが変わっている
    for (auto& n : num) n -= 5;  // もとに戻す

    cout << "auto& ---" << endl;
    for (auto& s : str) {  // sはstr要素の参照
        s += 2;            // sを変更したら元の値も変わる
        cout << s << endl;
    }
    cout << str << endl;  // 元のデータ
    for (auto& s : str) s -= 2;  // もとに戻す


    cout << "const auto& ---" << endl;
    for (const auto& n : num) {   // nはnum要素の、読み込み専用の参照
        //n += 5;                 // nを変更しようとするとコンパイルエラー
    }


    cout << "auto&& ---" << endl;
    for (auto&& n : num) {   // nはnum要素の参照
        n += 5;             // nを変更すると元データも変わる
        cout << n << endl;
    }
    for (auto n : num) cout << n << endl;  // 元データが変わっている
    for (auto& n : num) n -= 5;  // もとに戻す

    cout << "auto&& ---" << endl;
    for (auto&& s : str) {  // sはstr要素の参照
        s += 2;            // sを変更したら元の値も変わる
        cout << s << endl;
    }
    cout << str << endl;  // 元のデータ
    for (auto& s : str) s -= 2;  // もとに戻す




    vector<bool> vb = {0, 0, 0};

    cout << "auto&& ---" << endl;
    for (auto&& a : vb) {  // sはstr要素の参照
        cout << a << endl;
    }

/*
    // この例はエラーになる
    cout << "auto& ---" << endl;
    for (auto& a : vb) {  // sはstr要素の参照
        cout << a << endl;
    }
*/

}
