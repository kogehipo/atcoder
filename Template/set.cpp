// 問題 setとmap
// 解説 https://qiita.com/bestfitat/items/84b8750ba87cd2ab2633

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

int main()
{
    //////////////////////////////
    // setは重複を許さない順序付き集合
    //////////////////////////////

    // 空のsetを宣言
    //set<int> st;

    // 初期化して宣言
    set<int> st{1, 2, 3};

    cout << "-- 代入" << endl;
    st = {1, 3, 6};  // 代入すると初期値は消えてしまう
    for (auto s : st) cout << s << endl;

    cout << "-- 挿入" << endl;
    st.insert(3);  // 挿入しても同じ値があるので変化なし
    st.insert(5);  // 挿入される
    for (auto s : st) cout << s << endl;

    cout << "-- イテレータ" << endl;
    auto itr = st.begin();  // イテレータ
    // cout << *(itr+1) << endl;  // setのイテレータはランダムアクセスできないのでエラー
    cout << *itr << endl;
    cout << *(++itr) << endl;
    cout << *(--itr) << endl;

    cout << "-- ループ" << endl;
    for (auto itr = st.begin(); itr!=st.end(); itr++) {
        cout << *itr << endl;
    }

    cout << "-- 削除" << endl;
    st.erase(2);  // 元々無いので何も起きない
    st.erase(3);  // 削除される
    for (auto s : st) cout << s << endl;


    //////////////////////////////
    // multisetは重複した値を持てる
    //////////////////////////////

    // 空のsetを宣言
    //set<int> mst;

    // 初期化して宣言
    multiset<int> mst{1, 2, 3};

    cout << "-- 代入" << endl;
    mst = {1, 3, 6};  // 代入すると初期値は消えてしまう
    for (auto s : mst) cout << s << endl;

    cout << "-- 挿入" << endl;
    mst.insert(3);  // 3は存在するが重複して登録される
    mst.insert(5);  // 挿入される
    for (auto s : mst) cout << s << endl;

    cout << "-- イテレータ" << endl;
    auto mitr = mst.begin();  // イテレータ
    // cout << *(itr+1) << endl;  // setのイテレータはランダムアクセスできないのでエラー
    cout << *mitr << endl;
    cout << *(++mitr) << endl;
    cout << *(--mitr) << endl;

    cout << "-- 削除" << endl;
    mst.erase(2);  // 元々無いので何も起きない
    mst.erase(3);  // 削除される。複数あれば全部削除される。
    for (auto s : mst) cout << s << endl;

    cout << "-- 検索" << endl;
    if (mst.find(4) != mst.end()) {cout << "Found\n";} else {cout << "Not found\n";}
    if (mst.find(5) != mst.end()) {cout << "Found\n";} else {cout << "Not found\n";}

    return 0;
}
