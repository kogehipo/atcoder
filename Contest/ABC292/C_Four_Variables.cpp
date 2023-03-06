#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc292/tasks/abc292_c
// 解説 

// nの約数を全て配列に入れて返す
vector<long long> divisors(long long n) {
    vector<long long> res;
    for (long long i=1; i*i<=n; ++i) {
        if (n%i == 0) {
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    //sort(res.begin(), res.end());  // 昇順 ←この問題ではソートは不要
    return res;
}

int main()
{
/*
    // これでもパスするが、実行時間が約1秒かかる
    int N;
    cin >> N;
    int ans = 0;
    for (int AB=1; AB<N; AB++) {
        int CD = N-AB;
        // 約数の個数を調べる
        int nAB = divisors(AB).size();
        int nCD = divisors(CD).size();
        ans += nAB * nCD; 
    }
    cout << ans << endl;
    return 0;
*/

    int N;
    cin >> N;

    // 予め計算することで実行時間が半減する
    vector<int> div(N+1);
    for (int n=1; n<N; n++)
        div[n] = divisors(n).size();

    int ans = 0;
    for (int AB=1; AB<N; AB++) {
        int CD = N-AB;
        // 約数の個数を調べる
        int nAB = div[AB];
        int nCD = div[CD];
        ans += nAB * nCD; 
    }
    cout << ans << endl;
    return 0;
}
