// 問題 https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 次の２行を付けると標準入力の代わりにファイルから読む。
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;
    cout << n << endl;

    struct Point {
        int x;
        int y;
    };
    Point p[n];

    for (int i=0; i<n; i++) cin >> p[i].x >> p[i].y;
    for (int i=0; i<n; i++) cout << p[i].x << "," << p[i].y << endl;

    // n個の中から2個の組み合わせi,jを選ぶ
    int d, max_d = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++ ) {
            int left  = min(x[i], x[j]);
            int right = max(x[i], x[j]);
            int low   = min(y[i], y[j]);
            int up    = max(y[i], y[j]);
            int w = right - left;
            int h = up - low;



            // 2点i,jの距離の二乗を求める（大小関係を見るため）
            d = abs(x[i]-x[j]) * abs(x[i]-x[j]) + abs(y[i]-y[j]) * abs(y[i]-y[j]);
        }
    }


    // ファイルに出力する
    ofstream ofs("output.txt");
    ofs << "あいうえお　かきくけこ" << std::endl;

    return 0;
}
