#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main() {
    string S, T;
    cin >> S >> T;
    vector<int> s(26,0), t(26,0);
    int aS=0, aT=0;  // '@'の数

    for (char c : S) {
        if (c == '@') aS++;
        else s[c - 'a']++;
    }
    for (char c : T) {
        if (c == '@') aT++;
        else t[c - 'a']++;
    }
    rep(i, 26) {
        if (s[i] == t[i]) continue;
        if (i == 0 || i == 2 || i == 3 || i == 4 || i == 14 || i == 17 || i == 19) {
            if (s[i] < t[i]) {
                // Sの'@'で補う
                aS -= t[i] - s[i];
            }
            if (s[i] > t[i]) {
                // Tの'@'で補う
                aT -= s[i] - t[i];
            }
        } else {
            if (s[i] != t[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if (aS < 0 || aT < 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}

/*   非常にマズイやりかた
int main()
{
    string S, T;
    cin >> S >> T;
    int aS=0, aT=0;  // '@'の数
    int xS=0, xT=0;  // 一致しない文字の数

    sort(all(S));
    sort(all(T));
    unsigned int s=0, t=0;
    while (s < S.size() || t < T.size()) {
        // Sの処理を終えた場合、Tの処理を続ける
        if (S.size() <= s) {
            if (T[t] == '@') {
                T[t] = ' ';
                aT++;
            } else {
                xT++;
            }
            t++;
        }
        // Tの処理を終えた場合、Sの処理を続ける
        else if (T.size() <= t) {
            if (S[s] == '@') {
                S[s] = ' ';
                aS++;
            } else {
                xS++;
            }
            s++;
        }

        else if (S[s] == '@')  { S[s] = ' '; aS++; s++; }  // '@'の数を数える
        else if (T[t] == '@')  { T[t] = ' '; aT++; t++; }  // '@'の数を数える
        else if (S[s] == T[t]) { S[s] = ' '; T[t] = ' '; s++; t++; }  // 一致する文字は消す
        else if (S[s] < T[t])  { s++; xS++; }  // 一致しない文字の数を数える
        else                   { t++; xT++; }  // 一致しない文字の数を数える
    }

    // 一致しない文字を@でカバーできるか？
    if ( (aT - xS) < 0 || (aS - xT) < 0) {
        cout << "No" << endl;
        return 0;
    }

    //cout << S << "xS=" << xS << endl;
    //cout << T << "xT=" << xT << endl;

    int i = 0;
    while (i < S.size()) {
        switch (S[i]) {
            case ' ': case 'a': case 't': case 'c':
            case 'o': case 'd': case 'e': case 'r':
                break;
            default:
                if (aT == 0) {
                    cout << "No" << endl;
                    return 0;
                }
                aT--;
                break;
        }
        i++;
    }
    i = 0;
    while (i < T.size()) {
        switch (T[i]) {
            case ' ': case 'a': case 't': case 'c':
            case 'o': case 'd': case 'e': case 'r':
                break;
            default:
                if (aS == 0) {
                    cout << "No" << endl;
                    return 0;
                }
                aS--;
                break;
        }
        i++;
    }

    if ((aT - xS) == (aS - xT)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
*/