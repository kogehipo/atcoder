// 問題 https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, A;
    cin >> N >> M;

    int group_point = 0;
    for (int n=0; n<N; n++) {
        int point = 0;
        for (int m=0; m<M; m++) {
            cin >> A;
            point = max(point, A);
        }
        //cout << "point: " << point << endl;
        group_point += point;
    }
    cout << group_point << endl;
    return 0;
}
