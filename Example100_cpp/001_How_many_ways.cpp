// 問題 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------

int main()
{
    while (true) {
        int n, x;
        cin >> n >> x;

        // nとxの両方が0なら終了
        if (n==0 && x==0) break;

        int count = 0;
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=j+1; k<=n; k++) {
                    if (i+j+k == x) count++;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}
