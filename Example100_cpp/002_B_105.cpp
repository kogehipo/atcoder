// 問題 https://atcoder.jp/contests/abc106/tasks/abc106_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int total = 0;
    for (int n=1; n<=N; n++) {
        int count = 2;  // 1とnは約数（自明）
        for (int i=3; i<=(int)(n/2); i+=2) {
            if (n%i == 0) {
                count++;
            }
        }
        if (count == 8) total++;
    }

    cout << total << endl;
    return 0;
}
