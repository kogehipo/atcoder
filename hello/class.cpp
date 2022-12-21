// 問題 
// 解説 https://ja.wikibooks.org/wiki/C%2B%2B/%E5%88%9D%E5%BF%83%E8%80%85%E3%82%80%E3%81%91/%E3%82%AF%E3%83%A9%E3%82%B9

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

// クラス定義
class Person {
public:  // publicなので外部から参照可能
    const char* name;
    int age;

    // コンストラクタ - クラス名が関数名
    //auto a = Car();

    // メンバ関数の宣言
    void disp();

};  // この；忘れないように（構造体の書き方と同じ）


// メンバ関数の定義（Car::を省いてクラスの内部に書いても良い）
void Person::disp()
{
    cout << "name = " << name
        << ", age = " << age << endl; 
}

int main() {
    auto a = Person();  // インスタンス
    a.name = "山田一郎";
    a.age = 40;
    cout << "a.name = " << a.name
         << ", a.age = " << a.age << endl;
    a.disp();  // メンバ関数を呼び出す
}
