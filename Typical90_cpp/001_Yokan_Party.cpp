// 問題 https://atcoder.jp/contests/typical90/tasks/typical90_a
// 解説 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, L, K;
    int *A;
    cin >> N >> L;
    cin >> K;

    A = (int*)malloc(sizeof(int)*N);
    sort(A, A+N);

    // あり得るscoreの最善値
    int max_score = (int)L/(K+1);




    int score = 0;

    // N個の切れ目からK個を選ぶすべての組み合わせ
    for (int n=0; n<N; n++) {

    }


    cout << score << endl;
    return 0;
}
