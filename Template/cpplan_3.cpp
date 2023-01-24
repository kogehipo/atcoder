/*
    C++言語の基本テンプレート
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;


int main()
{

////////////////////////////////
// 演算
////////////////////////////////

    int i, j;
    i = 8;
    j = 5;

    cout << "--- 演算" << endl;
    cout << "足し算 " << i + j << endl;
    cout << "引き算 " << i - j << endl;
    cout << "掛け算 " << i * j << endl;
    cout << "割り算 " << i / j << endl;
    cout << "割った余り " << i % j << endl;
    cout << "最大値 " << max(i, j) << endl;
    cout << "最小値 " << min(i, j) << endl;
    cout << i << " をポストインクリメント " << i++ << " もう一度見ると " << i << endl;
    cout << i << " をプリインクリメント " << ++i << endl;
    cout << i << " をポストデクリメント " << i-- << " もう一度見ると " << i << endl;
    cout << i << " をプリデクリメント " << --i << endl;

    // 「X 演算子= Y」は「X = X 演算子 Y」と同じ。
    cout << "--- 演算子= " << endl;
    i = 5;
    i += 2; cout << "足し算 " << i << endl;
    i -= 1; cout << "引き算 " << i << endl;
    i /= 2; cout << "割り算 " << i << endl;
    i *= 2; cout << "掛け算 " << i << endl;

    bool a, b;
    a = true;
    b = false;

    cout << "--- 論理演算" << endl;
    cout << "真 " << a << endl;
    cout << "偽 " << b << endl;
    cout << "真の否定 " << !a << endl;
    cout << "偽の否定 " << !b << endl;
    cout << "論理和 " << (a || b) << endl;
    cout << "論理積 " << (a && b) << endl;

    i = 0b0011;
    j = 0b0110;

    cout << "--- ビット演算" << endl;
    cout << "ビット表現 " << i << ' ' << j << endl;
    cout << "ビット反転 " << ~i << ' ' << ~j << endl;
    cout << "ビット論理和 " << (i | j) << endl;
    cout << "ビット論理積 " << (i & j) << endl;

    cout << "i の下から3桁目を見る " << ((i & (1 << 2)) ? 1 : 0) << endl;
    cout << "j の下から3桁目を見る " << ((j & (1 << 2)) ? 1 : 0) << endl;
    cout << "i の下から3桁目を立てる " << (i |= 0b0100) << endl;
    cout << "i の下から3桁目を落とす " << (i &= ~0b0100) << endl;

    cout << "ビット左シフト " << (i << 2) << endl;
    cout << "ビット右シフト " << (j >> 2) << endl;


////////////////////////////////
// 条件式
////////////////////////////////

    // if文

    // switch文

////////////////////////////////
// 関数
////////////////////////////////


////////////////////////////////
// 構造体
////////////////////////////////


////////////////////////////////
// クラス
////////////////////////////////


    return 0;
}
