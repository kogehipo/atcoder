/*
    C++言語の基本テンプレート
    （C言語については触れません。割り切りました。）
*/

// このファイルの練習内容は複数に分かれている。
// EXCERCISEの値を 1, 2 と切り替えてみること
#define EXERCISE 1

#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;


int main()
{

#if EXERCISE == 1

////////////////////////////////
// 繰り返しループ
////////////////////////////////

    // for文は (最初に1度実行される; 続ける条件; ループ毎の最後に実行される) と書く
    // for文は、あとに続く1文、または1ブロックを繰り返す。
    // （複数文を繰り返すにはブロックにする必要あり）
    // ループを仲介するパラメータ変数(iなど)はfor文内で宣言すると
    // プログラムの他の部分に影響を与えないので安全である。
    // （意図的にそうしない場合もある）

    int N = 3;

    cout << "---" << endl << "N回繰り返す（0〜N-1）" << endl;
    for (int i=0; i<N; i++) cout << i << endl;

    cout << "---" << endl << "rep()を使って、N回繰り返す（0〜N-1）" << endl;
    rep(i, 0, N) cout << i << endl;

    cout << "---" << endl << "1からNまで繰り返す（1〜N）" << endl;
    for (int i=1; i<=N; i++) cout << i << endl;

    cout << "---" << endl << "Nから1まで繰り返す" << endl;
    for (int i=N; 1<=i; i--) cout << i << endl;

    cout << "---" << endl << "1から10まで奇数だけ繰り返す" << endl;
    for (int i=1; i<=10; i+=2) cout << i << endl;

    cout << "---" << endl << "2重ループ" << endl;
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            cout << "(" << i << "," << j << ") ";
        }
        cout << endl;
    }


    // while文は (続ける条件) と書く
    // while文は、あとに続く1ブロックを繰り返す。
    // while (1) {〜} で永久ループを作れる。while(true) {〜} も同等。

    cout << "---" << endl << "whileでN回繰り返す（0〜N-1）" << endl;
    int i = 0;
    while (i<N) {
        cout << i << endl;
        i++;
    }

    cout << "---" << endl << "whileで2から10まで偶数だけ出力" << endl;
    i = 2;
    while (i<=10) {
        cout << i << endl;
        i += 2;
    }

    cout << "---" << endl << "whileで10まで奇数だけ出力" << endl;
    i = 0;
    while (i<=10) {
        if (i%2) cout << i << endl;
        i++;
    }

    cout << "---" << endl << "whileで10まで奇数だけ出力（別解）" << endl;
    i = 0;
    while (1) {
        if (10 < i) {
            break;      // breakで終了
        }
        else if (i%2 == 0) {
            i++;
            continue;   // continueで継続 
        }
        cout << i << endl;
        i++;
    }

    // do〜while文は do {} (続ける条件); と書く

    cout << "---" << endl << "do〜whileでN回繰り返す（0〜N-1）" << endl;
    i = 0;
    do {
        cout << i << endl;
        i++;
    } while (i<N);


#elif EXERCISE == 2

////////////////////////////////
// 配列
////////////////////////////////

    // 配列はデータ型と大きさを指定して宣言する
    int A[3];

    int N = 3;
    int B[N];  // 大きさに変数を使えるのはC++の特徴（ただし大きさの変更はできない）

    int C[3] = {10, 20, 30};  // 初期値付きの宣言
    int D[3] = {};            // 配列を0で初期かする方法

    cout << "---" << endl << "配列に代入、参照" << endl;
    for (int i=0; i<3; i++) A[i] = i*2;    // 配列の要素には添字indexでアクセスする
    for (int i=0; i<3; i++) cout << A[i] << endl;

    cout << "---" << endl << "1からNまでのデータを扱う（競プロでよくあるパターン）" << endl;
    int S[N+1];  // データ番号をindexに使いたいのでS[0]は使わない。
    S[0] = 0;
    for (int i=1; i<=N; i++) A[i] = i;
    for (int i=0; i<=N; i++) cout << A[i] << endl;


    // 文字列 "abc" はcharの配列。 ' 'で囲まれたのは文字列ではなく1文字
    // 文字列の1文字ずつは char型 のデータ
    // 文字列の末尾には '\0' が終端記号として存在する

    cout << "---" << endl << "文字列を分解して出力" << endl;
    char s[] = "abc";
    cout << s << " の文字数は " << sizeof(s) << endl; // '\0'のぶん、1大きい
    for (int i=0; s[i]!='\0'; i++) cout << s[i] << endl;
    for (int i=0; i<(sizeof(s)-1); i++) cout << s[i] << endl;

    cout << "---" << endl << "１文字ずつ操作して文字列を作る" << endl;
    char s2[10];
    s2[0] = 'x';   // "〜"は文字列、'X'は1文字
    s2[1] = 'y';
    s2[2] = 'z';
    s2[3] = '\0';  // 終端記号を忘れない
    cout << s2 << endl;

    cout << "---" << endl << "2次元配列" << endl;
    int array[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }


#elif EXERCISE == 3

////////////////////////////////
// ポインタ
////////////////////////////////

    // &は参照を表す（参照=そのデータのアドレス）
    int a = 9;
    cout << "a の値 " << a << endl;
    cout << "a の参照 " << &a << endl;

    // 配列の名前は、配列の先頭アドレス（つまり参照）
    int A[5] = {10, 20, 30, 40, 50};
    cout << "A[0] の値 " << A[0] << endl;
    cout << "A[1] の値 " << A[1] << endl;
    cout << "A の値（参照に相当）" << A << endl;

    // *はポインタの指す内容
    int *p;  // intのポインタp
    p = &a;
    cout << "p の値 " << p << endl;
    cout << "p の指す値 " << *p << endl;
    *p = 55;  // aのアドレスに値を書き込む
    cout << "a の値 " << a << endl;

    // ポインタを増減して配列の要素にアクセス
    p = A;
    for (int i=0; i<5; i++) cout << *(p+i) << ' ';
    cout << endl;

    for (int i=0; i<5; i++) cout << *p++ << ' ';
    cout << endl;

#endif


    return 0;
}
