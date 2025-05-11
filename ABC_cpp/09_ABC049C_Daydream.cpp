// 問題 https://atcoder.jp/contests/abs/tasks/arc065_a
// 解説 https://qiita.com/drken/items/fd4e5e3630d0f5859067

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

#define CASE 2

#if CASE == 1
// 正攻法で先頭から試みたもの。
// サンプル３個は正答するが不完全で、提出するとWAとなる。
int main()
{
    string S;
    cin >> S;

    string words[4] = {"dream", "dreamer", "erase", "eraser"};

    bool failed = false;
    int i = 0;
    while ( i < (int)S.length() ) {
        // 文字列終わり
        if (S[i] == '\0') {
            break;
        }
        // １文字目が'd'の場合
        else if (S[i] == 'd') {
            // 'd'のあと'ream'と続かなかったらNO
            if (S[i+1] != 'r' &&
                S[i+2] != 'e' &&
                S[i+3] != 'a' &&
                S[i+4] != 'm') {
                failed = true;
                break;
            }
            // 'dream'で終わっていたらYES
            else if (S[i+5] == '\0') {
                break;
            }
            // 'dream'のあと'd'が来たら次の'dream〜'
            else if (S[i+5] == 'd') {
                i += 5;
                continue;
            }
            // 'dream'のあと、'dreamer'となるか、'erase〜'となるか
            else if (S[i+5] == 'e') {
                if (S[i+6] != 'r' ) {
                    failed = true;
                    break;
                } else if (S[i+7] == 'a') {
                    i += 5;
                    continue;
                } else {
                    i += 7;
                    continue;
                }
            }
            else {
                failed = true;
                break;
            }
        }
        else if (S[i]   != 'e' ||
                 S[i+1] != 'r' ||
                 S[i+2] != 'a' ||
                 S[i+3] != 's' ||
                 S[i+4] != 'e') {
            failed = true;
            break;
        }
        else if (S[i+5] == '\0') {
            break;
        }
        else if (S[i+5] == 'r') {
            i += 6;
            continue;
        }
        else {
            i += 5;
            continue;
        }
    }

    if (failed) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
#endif


#if CASE == 2
int main()
{
    string S;
    cin >> S;

// dream    maerd
// dreamer  remaerd
// erase    esare
// eraser   resare

    string words[4] = {"dream", "dreamer", "erase", "eraser"};

    reverse(S.begin(), S.end());
    for (int i=0; i<4; i++) reverse(words[i].begin(), words[i].end());

    int j = 0;
    while ( j < S.length() ) {
        bool matched = false;
        for (int i=0; i<4; i++) {
            if (S.compare(j, words[i].length(), words[i]) == 0) {
                j += words[i].length();
                matched = true;
                //cout << "DEBUG: " << words[i] << endl;
                break;
            }
        }
        if (!matched) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
#endif
