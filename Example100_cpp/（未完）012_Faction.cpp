#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

// ここから下はオプション。問題によって選択すること。

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc002/tasks/abc002_4
// 解説 


int main()
{
    int N, M;
    cin >> N >> M;
    set<Point> r;  // 人間関係を格納するset

    rep(m, 0, M) {  // M個の人間関係
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
    rep(n, 1, N+1) members.push_back(n);

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
