#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

// 参考 https://qiita.com/mosamosa/items/79cf230ae22ee71f6801
// 参考 http://caprest.hatenablog.com/entry/2016/05/29/181102
// N個から(N以下)個を選ぶ組み合わせの数(いわゆるパスカルの三角形)をvectorで返す
vector<vector<long long>> pascal_triangle(int N) {

    // N+1*N+1の2次元vectorを0で初期化しておく
    // ここにパスカルの三角形を作る
    vector<vector<long long>> v(N+1, vector<long long>(N+1, 0));

    for (int i=0; i<=N; i++) {
        v[i][0] = 1;  // N個から0個を選ぶのは1通り
        v[i][i] = 1;  // N個からN個を選ぶのは1通り
    }

    // パスカルの三角形を埋めていく
    for (int n=1; n<=N; n++) {  // 母集合の大きさ：1からNまで繰り返す
        for (int k=1; k<n; k++) {  // 各集合で、1からその大きさn-1まで繰り返す
            v[n][k] =           // n個からk個を選ぶ組合せは、
                v[n-1][k-1] +   // 自分を選んだ場合、n-1からk-1を選ぶ組合せと、
                v[n-1][k];      // 自分を選ばなかった場合、n-1からkを選ぶ組合せ、の和
        }
    }

    // 確認のためパスカルの三角形を表示
    for (int n=0; n<=N; n++) {
        for (int k=0; k<=N; k++) {
            cout << v[n][k] << ' ';
        }
        cout << ": " << n << "個からK個を選ぶ組合せの数" << endl;
    }

    return v;
}

int combination(int N, int K)
{
    return pascal_triangle(N)[N][K];
}

int main()
{
    // 3から2個選ぶ組み合わせの数は
    cout << combination(3,2) << endl;
}
