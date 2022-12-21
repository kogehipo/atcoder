// 問題 https://atcoder.jp/contests/abc106/tasks/abc106_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int total = 0;  // 答え

    for (int n=1; n<=N; n++) {
        if (n%2 == 0) continue;  // nが偶数ならスキップ

        // nの約数の数を求める
        int count = 2;  // 1とnは約数（自明）
        for (int i=3; i<=(int)(n/2); i+=2) {
            if (n%i == 0) {  // 約数を見つけた
                count++;  // 約数の数を+1
            }
        }

        if (count == 8) total++;  // 約数の数が8なら答えを+1
    }

    cout << total << endl;
    return 0;
}

