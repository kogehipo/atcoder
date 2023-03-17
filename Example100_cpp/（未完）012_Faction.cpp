#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc002/tasks/abc002_4
// 解説 

int main()
{
    int N, M;
    cin >> N >> M;
    set<Point> r;  // 人間関係を格納するset

    rep(m, M) {  // M個の人間関係
        int a, b;
        Point p;
        cin >> a >> b;
             if (a == b) { continue; }  // ありえない
        else if (a < b)  { p.x = a; p.y = b; }  // 小さい方をxに格納
        else             { p.x = b; p.y = a; }
        r.insert(p);
    }

    // 議員数Nのvectorを作る
    vector<int> members;
    range(n, 1, N+1) members.push_back(n);

    do {
        //rep (i, N) cout << array[i] << " ";
        //cout << endl;
        rep (i, N-1) {
            all_sum += d[array[i]][array[i+1]];
            //cout << d[array[i]][array[i+1]] << endl;
        }
        count++;
    } while (next_permutation(members.begin(), members.end());





    int max_faction;
    for (max_faction=N; 1<=max_faction; --max_faction) {
    }

    return 0;
}
