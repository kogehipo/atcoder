// 問題 https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

#define CASE 2

#if CASE == 1
// Sの方を全探索する方法。これをするとTLEになる。
int main()
{
    int N;
    string S;
    cin >> N;
    cin >> S;
    set<int> st;

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            for (int k=j+1; k<N; k++) {
                st.insert((S[i]-'0')*100 +  (S[j]-'0')*10 + S[k]-'0');
            }
        }
    }

    cout << st.size() << endl;
    return 0;
}
#endif

#if CASE == 2
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
        sprintf(a, "%03d", i);

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
#endif
