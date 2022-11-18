// 問題 https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N;
    cin >> S;

    char a[10];
    int count = 0;

    // "000"から"999"まで全探索する
    for (int i=0; i<=999; i++) {
        snprintf(a, 10, "%03d", i);

        // ３桁の先頭から探す
        int idx = 0;
        for (int n=0; n<N; n++) {
            if (S[n] == a[idx]) {  // 探している文字が見つかったら、
                idx++;             // 次の文字を探す。
            }
            if (idx == 3) {        // ３文字見つかったら、
                count++;           // 見つかった数をカウントアップして、
                break;             // 次に行く
            }
        }
    }
    cout << count << endl;
    return 0;
}


#if 0
// Nの方を全探索する方法。これをするとTLEになる。
int main()
{
    int N;
    string S;
    cin >> N;
    cin >> S;

    bool pw[1000];
    for (int i=0; i<1000; i++) pw[i] = false;

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            for (int k=j+1; k<N; k++) {
                char a[4];
                a[0] = S[i];
                a[1] = S[j];
                a[2] = S[k];
                a[3] = '\0';
                pw[atoi(a)] = true;
            }
        }
    }

    int count = 0;
    for (int i=0; i<1000; i++) if (pw[i]) count++;
    cout << count << endl;
    return 0;
}
#endif
