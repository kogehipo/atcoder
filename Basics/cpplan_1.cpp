/*
    C++言語の基本テンプレート
    （C言語については触れません。割り切りました。）
*/

// このファイルの練習内容は複数に分かれている。
// EXCERCISEの値を 1, 2 と切り替えてみること
#define EXERCISE 2

////////////////////////////////
// コメント
////////////////////////////////

/* 
    コメントの書き方(1)
    ／* から *／ までの範囲はコメント（／は半角文字を使うこと）
    行の途中からでもOK。
    途中に改行が入っても、いなくてもコメントと見なされる。
*/

// コメントの書き方(2)
// "//"から行末はコメントと見なされる
// 行の途中からでもOK。

#if 0
    // 厳密にはコメントではないが、行頭の #if 0 〜 #endif で
    // 囲まれば部分をコンパイラに無視させることができる。
    // これをコメント機能として使ったり、プログラムの一部の動作を
    // 無効化することができる。
    iiinnt XYZ;  // 左のコードは見違っているが無視されるのでエラーは出ない。
    // このファイル内で使われている #define EXERCISE の使い方も参考に。
#endif


////////////////////////////////
// 構文
////////////////////////////////

// Pythonとぜんぜん違う！
// 構文はの末尾は ; で区切られる。
// 途中で改行しても良い（空白と同じ扱い） ただし文字列定数の途中の改行には注意。
// 複数の構文を { } でまとめて１ブロックにできる。ブロックの最後には ; は付けない。
// インデント（字下げ）は文法的には無意味であるが、可読性のために必要。


////////////////////////////////
// ヘッダー情報
////////////////////////////////

// 「ヘッダー」は文法用語ではないが、慣用的にファイル冒頭に
// 書くことでコーディングの効率化etc.の効果がある
// 参照： https://learn.rdc.oit.ac.jp/procon_template/

// GCCのg++を競プロで使う場合、次の2行は常に書く
#include <bits/stdc++.h>
using namespace std;

// 記述の簡略化、データ型宣言、定数 etc. をヘッダーに書いておく
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;


////////////////////////////////
// グローバル変数
////////////////////////////////

// main()の外側で定義した変数はグローバル変数で、
// プログラムの実行中常に存在し、どこからでも参照できる。
int global_var_1;  // グローバル変数の宣言（グローバル変数は0で初期化される）
int global_var_2 = 999;  // 初期値を設定したグローバル変数の宣言

// main() や関数の中で定義された変数はローカル変数。
// ローカル変数は明示的に初期化する、または値を代入して使うこと。
// ローカル変数はその関数内、またはブロック内でのみ存在し、有効である。
// これを変数の「スコープ」という。

////////////////////////////////
// main()関数
////////////////////////////////

// ・C言語、C++言語には必ずメイン関数 main() が存在する。
// ・main() 関数は int型 で、そのリターン値はシステム側で利用される。
//   通常、処理が正常に終われば 0、エラーならそれ以外を返すが、
//   その値を利用するかどうかはシステム依存。（競プロでは無視されることが多い）
// ・main() の内容は { } で囲む。
int main()
{

#if EXERCISE == 1

////////////////////////////////
// cin, cout を使ったデータ入出力
////////////////////////////////

    // 標準出力デバイス（通常はターミナルコンソール）に
    // cout でデータ（変数や定数）を出力する。
    // ・endl を出力すると改行する。
    // ・ << を繋げて幾つでも連続して出力できる。
    cout << "グローバル変数の確認: global_var_1=" << global_var_1
         << " global_var2=" << global_var_2<< endl;
    cout << "数値を入力してください。" << endl;
    // ・文字列最後に \n を付けても改行できる。
    cout << "（文字を入れると0と認識されます）\n";

    // 標準入力デバイス（通常はターミナルコンソールに接続されたキーボード）
    // から cin でデータ入力できる。
    int N;      // int型（数値）の変数を宣言
    cin >> N;   // 読み込んだ数値を変数にセットする
    cout << "読み込んだデータは " << N << " です。" << endl;

    // 文字列も読める
    cout << "何か文字列を入力してください。" << endl;
    string S;   // string型（文字列）の変数を宣言
    cin >> S;   // 読み込んだ数値を変数にセットする
    cout << "読み込んだデータは " << S << " です。" << endl;

    // 複数のデータ入力も可能。データの区切りはスペース、改行、タブが使える。
    cout << "数値を３つ入力してください。" << endl;
    int N1, N2, N3;         // int型（数値）の変数を宣言
    cin >> N1 >> N2 >> N3;   // 読み込んだ数値を変数にセットする
    cout << "読み込んだデータは " << N1 << " " << N2 << " " << N3 << " です。" << endl;

    // 配列へのデータ入力も可能。
    cout << "データの個数を入力してください。" << endl;
    int N4;     // int型（数値）の変数を宣言
    cin >> N4;
    int N4_array[N4];  // int型（数値）の配列変数を宣言。C++では変数でサイズ指定できる。
    cout << "数値を " << N4 << " 個入力してください。" << endl;
    for (int i=0; i<N4; i++) cin >> N4_array[i];   // 読み込んだ数値を配列にセット
    cout << "読み込んだデータは ";
    for (int i=0; i<N4; i++) cout << '(' << i << ')' << N4_array[i] << ' ';
    cout << "です。" << endl;

#elif EXERCISE == 2

////////////////////////////////
// データ型
////////////////////////////////

    // int は4バイトの数値を表すデータ型
    cout << "int型のサイズは " << sizeof(int) << " バイトです。" << endl;
    int i;         // 変数の宣言（ローカル変数の初期値は不定）
    int i2 = 999;  // 初期値を付けた宣言
    cout << "初期値の確認 i=" << i << " i2=" << i2 << endl;

    // int の最大数
    i = 0x7FFFFFFF;
    cout << "int で表せる最大数は " << i << " です。"<< endl;
    i = 0x80000000;
    cout << "int で表せる最小数は " << i << " です。"<< endl;
    unsigned int j = 0xFFFFFFFF;
    cout << "unsigned int で表せる最大数は " << j << " です。"<< endl;

    // long long は8バイトの数値を表すデータ型
    cout << "long long型のサイズは " << sizeof(long long) << " バイトです。" << endl;
    long long l;         // 変数の宣言（ローカル変数の初期値は不定）
    int l2 = 999;  // 初期値を付けた宣言
    cout << "初期値の確認 l=" << l << " l2=" << l2 << endl;

    // long long の最大数
    l = 0x7FFFFFFFFFFFFFFF;
    cout << "long long で表せる最大数は " << l << " です。"<< endl;
    l = 0x8000000000000000;
    cout << "long long で表せる最小数は " << l << " です。"<< endl;
    unsigned long long m = 0xFFFFFFFFFFFFFFFF;
    cout << "unsigned longlong で表せる最大数は " << m << " です。"<< endl;

    // char は1バイトで文字または数値を表すデータ型
    cout << "char型のサイズは " << sizeof(char) << " バイトです。" << endl;
    char c;         // 変数の宣言（ローカル変数の初期値は不定）
    int c2 = 'a';  // 初期値を付けた宣言
    cout << "初期値の確認 c=" << c << " c2=" << c2 << endl; // coutでは数値として扱われる

    printf("c2を文字として出力すると %c\n", c2);  // C言語の printf() も使える

    // 数値データとしての char の最大数
    c = 0x7F;
    cout << "char で表せる最大数は " << (int)c << " です。"<< endl;
    c = 0x80;
    cout << "char で表せる最小数は " << (int)c << " です。"<< endl;
    unsigned char c3 = 0xFF;
    cout << "unsigned char で表せる最大数は " << (int)c3 << " です。"<< endl;

    // bool は1バイトで論理（真偽）を表すデータ型
    cout << "bool型のサイズは " << sizeof(bool) << " バイトです。" << endl;
    bool b;    // 変数の宣言
    b = true;  // 値を代入（trueは1の値を持つ）
    if (b) cout << "b は" << b << "です。" << endl;
    else   cout << "b は" << b << "です。" << endl;
    b = false;  // 値を代入（falseは0の値を持つ）
    if (b) cout << "b は" << b << "です。" << endl;
    else   cout << "b は" << b << "です。" << endl;

    // 浮動小数点
    cout << "float型のサイズは " << sizeof(float) << " バイトです。" << endl;
    cout << "double型のサイズは " << sizeof(double) << " バイトです。" << endl;
    unsigned long long ull=1;
    rep(i, 0, 60) ull = ull * 2;
    double d;
    d = pow(2, 60);  // 標準関数pow()はdouble型の結果を返す
    cout << "整数型で計算した2の60乗は " << ull << " ですが、" << endl;
    cout << "doubleで計算した2の60乗は " << d << " になります。" << endl;
    cout << "浮動小数点を使うと桁落ち誤差が生じるので注意。" << endl;

    // キャスト
    i = INF;
    l = (long long)i;
    cout << "intをlong longにキャストします。 i=" << i << " l=" << l << endl;
    l = LINF;
    i = (int)l;
    cout << "long longをintにキャストします。 l=" << l << " i=" << i << " 失敗します。" << endl;

////////////////////////////////
// 定数
////////////////////////////////

    i = 255; cout << "i は " << i << " です。" << endl;
    i = 0xFF; cout << "16進で書いても i は " << i << " です。" << endl;
    i = 0b11111111; cout << "2進で書いても i は " << i << " です。" << endl;
    i = 0377; cout << "8進で書いても i は " << i << " です。" << endl;

    char ch;
    ch = 'a'; cout << "ch は " << ch << " です。" << endl;
    ch = 'a'; cout << "ch は数字で表すと " << (int)ch << " です。" << endl;
    ch = 'a'; cout << "ch と「c」の差分は " << 'c' - ch << " です。" << endl;

    char str[80] = "abc";
    cout << "str は " << str << " です。文字列は文字(char)の配列です。" << endl;
    cout << "配列として扱えば、2文字目(添字は1)は " << str[1] << " です。" << endl;
    str[1] = 'X';
    cout << "配列として扱って変更もできます。2文字目(添字は1)を変更すると " << str << " となります。" << endl;

#endif

    return 0;
}