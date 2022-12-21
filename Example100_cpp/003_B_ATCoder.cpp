// 問題 https://atcoder.jp/contests/abc122/tasks/abc122_b

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

int main()
{
    string S;
    cin >> S;

    int max_count = 0;
    int count = 0;

    rep(i, 0, S.length()) {
        switch (S[i]) {
            case 'A':
            case 'C':
            case 'G':
            case 'T':
                count++;
                break;
            default:  // ACGT以外の文字が見つかった
                if (max_count < count) max_count = count;
                count = 0;
                break;
        }
        // ちょうどACGTで終わる場合もあるので、もう一度最大値を確認する
        if (max_count < count) max_count = count;
    }

    cout << max_count << endl;
    return 0;
}
