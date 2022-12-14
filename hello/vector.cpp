// 解説 vectorの使い方

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main()
{
    vector<int> num = {10, 50, 100};
    vector<string> str = {"apple", "bird", "cat"};

    cout << "--- vectorの基本" << endl; //-----------------------------

    cout << "size = " << num.size() << endl;  // サイズ
    for (auto&& n : num) cout << n << endl;

    cout << "size = " << str.size() << endl;
    for (auto s : str) {
        cout << s << endl;
    }

    cout << "--- イテレータ" << endl; //-----------------------------

    auto it = num.begin();
    cout << "begin() " << it[0] << endl;
    cout << "next of begin() " << it[1] << endl;
    it++;
    cout << "next of begin() " << *it << endl;

    it = num.end();
    cout << "back of end() " << it[-1] << endl;
    cout << "end() " << it[0] << endl;
    cout << "next of end() " << it[1] << endl;

    cout << "--- 逆イテレータ" << endl; //-----------------------------

    auto it2 = num.rbegin();
    cout << "rbegin() " << it2[0] << endl;
    cout << "next of begin() " << it2[1] << endl;
    it2++;
    cout << "next of begin() " << *it2 << endl;

    it2 = num.rend();
    cout << "back of rend() " << it2[-1] << endl;
    cout << "rend() " << it2[0] << endl;
    cout << "next of rend() " << it2[1] << endl;

    cout << "---" << endl; //-----------------------------

}
