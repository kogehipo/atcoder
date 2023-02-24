#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_bn
// 解説 


int main()
{
    int N;
    cin >> N;
    vector<pair<int,int>> movie(N);    // N本の映画情報
    rep(n, N) cin >> movie[n].second   // second:開始時刻
                    >> movie[n].first; // first:終了時刻（この順にソートしたいから）
    sort(movie.begin(), movie.end());  // 終了時刻の順にソート

    int ans = 0;  // 見た映画の本数
    int limit = movie.size();  // vectorサイズ
    int i = 0;  // vectorのインデックス
    while (i<limit) {
        ans++;  // 映画を一本見る
        int time = movie[i].first;  // 終了時刻
        while (movie[i].second < time) {  // 次の映画の開始時刻が、終了時刻以降になるまでインデックスを進める
            i++;
            if (limit <= i) break;  // 見れる映画がなくなったら終わり
        }
    }
    cout << ans << endl;
    return 0;
}
