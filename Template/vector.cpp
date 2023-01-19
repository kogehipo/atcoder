// 解説 vectorの使い方
//    https://qiita.com/ysuzuki19/items/df872d91c9c89cc31aee

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
struct Point { int x, y; };

int main()
{
    // vectorの宣言： <型>はclass名なども使用できる
    vector<int> num = {10, 50, 100};
    vector<string> str = {"apple", "bird", "cat"};
    vector<Point> point(3, {2,3});  // 初期値付きで宣言する方法（要素数, 初期値）

    cout << "--- vectorの基本" << endl; //-----------------------------
    cout << "size = " << num.size() << endl;  // サイズ
    for (auto n : num) cout << n << endl;

    cout << "size = " << str.size() << endl;
    for (auto s : str) cout << s << endl;

    cout << "size = " << point.size() << endl;
    for (auto p : point) cout << "x=" << p.x << " y=" << p.y << endl;

    cout << "--- 検索" << endl; //-----------------------------
    if (find(str.begin(), str.end(), "dog") == str.end()) {
        cout << "\"dog\" was found" << endl;
    } else {
        cout << "\"dog\" was not found" << endl;
    }

    if (find(str.begin(), str.end(), "cat") == str.end()) {
        cout << "\"cat\" was found" << endl;
    } else {
        cout << "\"cat\" was not found" << endl;
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

    cout << "--- 要素の追加と削除" << endl; //-----------------------------
    num.push_back(999);  // 末尾に要素を追加
    for (auto n : num) cout << n << endl;
    cout << "--" << endl;
    num.pop_back();   // 末尾の要素を削除
    for (auto n : num) cout << n << endl;
    cout << "--" << endl;
    num.insert(num.begin()+2, 90);   // 要素を挿入
    num.insert(num.begin()+3, 91);   // 要素を挿入
    for (auto n : num) cout << n << endl;

    cout << "---" << endl; //-----------------------------

    cout << "--- 最小値・最大値" << endl; //-----------------------------
    cout << "最小値 " << *min_element(num.begin(), num.end()) << endl;  //イテレータが返ることに注意
    cout << "最大値 " << *max_element(num.begin(), num.end()) << endl;

    // イテレータを取得してvectorの添字に変換する
    vector<int>::iterator maxIt = max_element(num.begin(), num.end());
    int maxIndex = distance(num.begin(), maxIt);
    cout << "最大値2 " << num[maxIndex] << endl;

}
