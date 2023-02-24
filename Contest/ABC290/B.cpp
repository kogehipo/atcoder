#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc290/tasks/abc290_b
// 解説 


int main()
{
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    int count = 0;
    for (int i=0; i<N; i++) {
        if (count < K && S[i] == 'o') {
            cout << 'o';
            count++;
        }
        else {
            cout << 'x';
        }
    }
    cout << endl;
    return 0;
}
