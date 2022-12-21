// 問題 setとmap
// 解説 https://qiita.com/_EnumHack/items/f462042ec99a31881a81

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

int main()
{
    //////////////////////////////
    // mapは連想配列。ここの例は 文字列:数値 のデータを扱う。
    //////////////////////////////

    // 空のmapを宣言
    map<string, int> m1;

    // 初期化して宣言
    map<string, int> m2{
            {"poke", 100},
            {"beaf", 180},
            {"chiken", 70} };

    cout << "-- キー指定で参照" << endl;
    string key = "poke";
    cout << key << " : " << m2[key] << endl;

    cout << "-- キー指定で参照（at()でもできる）" << endl;
    key = "poke";
    cout << key << " : " << m2.at(key) << endl;

    cout << "-- キー指定して代入" << endl;
    key = "beaf";
    m2[key] = 220;
    cout << key << " : " << m2[key] << endl;

    cout << "-- 全体を出力（イテレータでfor文を回す）" << endl;
    for (auto itr = m2.begin(); itr != m2.end(); itr++) {
        cout << itr->first << " : " << itr->second << endl;
    }

    cout << "-- 全体を出力（範囲ベースforループで）" << endl;
    for (const auto& item : m2) {
        cout << item.first << " : " << item.second << endl;
    }

    cout << "-- 全体を出力（キー＆値ペアで）" << endl;
    for (const auto& [key, value] : m2) {
        cout << key << " : " << value << endl;
    }

    cout << "-- イテレータは双方向。ただしランダムアクセスは出来ない" << endl;
    auto itr = m2.begin();
    cout << itr->first << " : " << itr->second << endl;
    itr++;
    cout << itr->first << " : " << itr->second << endl;

    itr = m2.begin();
    cout << itr->first << " : " << itr->second << endl;
    itr = next(itr, 2);  // ランダムアクセスは出来ないがnext()で進めることはできる
    cout << itr->first << " : " << itr->second << endl;

    auto itr2 = m2.end();
    itr2--;
    cout << itr2->first << " : " << itr2->second << endl;
    itr2--;
    cout << itr2->first << " : " << itr2->second << endl;

    cout << "-- 代入" << endl;
    m2 = {  {"apple", 100},
            {"orange", 70},
            {"banana", 140} };  // 代入すると初期値は消えてしまう
    for (const auto& [key, value] : m2) cout << key << " : " << value << endl;

    cout << "-- サイズ" << endl;
    cout << m2.size() << endl;

    cout << "-- 自動的に追加" << endl;
    cout << m2["some_fruits"] << endl;  // 存在しないkeyを参照すると自動的に追加される（値は0）
    cout << m2.size() << endl;  // 追加されたのでサイズは１大きくなる

    cout << "-- 挿入" << endl;
    m2["pinapple"] = 280;
    m2.insert(make_pair("grape",250));
    m2.emplace("lemon",110);
    for (const auto& [key, value] : m2) cout << key << " : " << value << endl;

    cout << "-- キーを検索（存在しなくても追加されることはない）" << endl;
    itr = m2.find("melon");
    if (itr == m2.end()) cout << "melon was not found" << endl;
    else cout << itr->first << " : " << itr->second << endl;

    itr = m2.find("apple");
    if (itr == m2.end()) cout << "apple was not found" << endl;
    else cout << itr->first << " : " << itr->second << endl;

    cout << "-- 削除" << endl;
    m2.erase("pinapple");
    for (const auto& [key, value] : m2) cout << key << " : " << value << endl;

    cout << "-- クリア" << endl;
    m2.clear();
    for (const auto& [key, value] : m2) cout << key << " : " << value << endl;

    return 0;
}
