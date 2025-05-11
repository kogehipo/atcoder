#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    // mapは連想配列。例は 文字列:数値 のデータを扱う。
 
    // 空のmapを宣言
    map<string, int> m;
 
    // 初期化して宣言
    map<string, int> mp{
            {"poke", 100},
            {"beaf", 180},
            {"chiken", 70} };
 
    cout << "-- キー指定で参照" << endl;
    string key = "poke";
    cout << key << " : " << mp[key] << endl;
    key = "fish";
    cout << key << " : " << mp[key] << endl;
 
    cout << "-- キー指定で参照（at()でもできる）" << endl;
    key = "poke";
    cout << key << " : " << mp.at(key) << endl;
 
    cout << "-- キー指定して代入" << endl;
    key = "beaf";
    mp[key] = 220;
    cout << key << " : " << mp[key] << endl;
 
    cout << "-- 全体を出力（イテレータでfor文を回す）" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        cout << itr->first << " : " << itr->second << endl;
    }
 
    cout << "-- 全体を出力（範囲ベースforループで）" << endl;
    for (const auto& item : mp) {
        cout << item.first << " : " << item.second << endl;
    }
 
    cout << "-- 全体を出力（キー＆値ペアで）" << endl;
    for (const auto& [key, value] : mp) {
        cout << key << " : " << value << endl;
    }
 
    cout << "-- イテレータは双方向。ただしランダムアクセスは出来ない" << endl;
    auto itr = mp.begin();
    cout << itr->first << " : " << itr->second << endl;
    itr++;
    cout << itr->first << " : " << itr->second << endl;
 
    itr = mp.begin();
    cout << itr->first << " : " << itr->second << endl;
    itr = next(itr, 2);  // ランダムアクセスは出来ないがnext()で進めることはできる
    cout << itr->first << " : " << itr->second << endl;
 
    auto itr2 = mp.end();
    itr2--;
    cout << itr2->first << " : " << itr2->second << endl;
    itr2--;
    cout << itr2->first << " : " << itr2->second << endl;
 
    cout << "-- 代入" << endl;
    mp = {  {"apple", 100},
            {"orange", 70},
            {"banana", 140} };  // 代入すると初期値は消えてしまう
    for (const auto& [key, value] : mp) cout << key << " : " << value << endl;
 
    cout << "-- サイズ" << endl;
    cout << mp.size() << endl;
 
    cout << "-- 自動的に追加" << endl;
    cout << mp["some_fruits"] << endl;  // 存在しないkeyを参照すると自動的に追加される（値は0）
    cout << mp.size() << endl;  // 追加されたのでサイズは１大きくなる
 
    cout << "-- 3通りの挿入" << endl;
    mp["pinapple"] = 280;
    mp.insert(make_pair("grape",250));
    mp.emplace("lemon",110);  // 推奨
    for (const auto& [key, value] : mp) cout << key << " : " << value << endl;
 
    cout << "-- キーを検索（存在しなくても追加されることはない）" << endl;
    itr = mp.find("melon");
    if (itr == mp.end()) cout << "melon was not found" << endl;
    else cout << itr->first << " : " << itr->second << endl;
 
    itr = mp.find("apple");
    if (itr == mp.end()) cout << "apple was not found" << endl;
    else cout << itr->first << " : " << itr->second << endl;
 
    cout << "-- 削除" << endl;
    mp.erase("pinapple");
    for (const auto& [key, value] : mp) cout << key << " : " << value << endl;
 
    cout << "-- クリア" << endl;
    mp.clear();
    for (const auto& [key, value] : mp) cout << key << " : " << value << endl;
 
    return 0;
}