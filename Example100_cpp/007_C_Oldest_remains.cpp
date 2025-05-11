// 問題 https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c
// 解説 https://kakedashi-engineer.appspot.com/2020/05/07/joi2007hoc/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
//---------------------------------------------------


// x,y座標を示す構造体を宣言
// pairを使うとfirst,secondの名前になって可読性が悪いので
struct Point {
    int x;
    int y;
};

// setで扱うには "<" の定義が必要
bool operator<(const Point &p1, const Point &p2)
{
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}


int main()
{
    // 標準入力・出力をファイルに切り替える
    //cin_from("input.txt");
    //cout_to("output.txt");

    int N;
    cin >> N;

    set<Point> p;

    // 点群の座標をsetに保存
    rep(n, 0, N) {
        Point a;
        cin >> a.x >> a.y;
        p.insert(a);
    }

    //sort(p.begin(), p.end());

    // 発見した正方形の最大サイズ
    int max_size = 0;

    // 点群から2点(p1,p2)を選ぶ
    for (auto&& p1 : p) {
        for (auto&& p2 : p) {

            int dx = p2.x - p1.x;
            int dy = p2.y - p1.y;
            if (dx == 0 && dy == 0) continue;  // 2点が同じ場合スキップ

            // 正方形を成す他の2点p3,p4の座標を決める
            Point p3, p4;
            p3.x = p1.x + dy;
            p3.y = p1.y - dx;
            p4.x = p2.x + dy;
            p4.y = p2.y - dx;

            // p3,p4が存在すれば正方形を発見
            if (p.find(p3) != p.end() &&
                p.find(p4) != p.end()) {
/*
                // 4辺について処理するので、同じ正方形が4回見つかる（改善の余地）
                cout << "Found: "
                    << p1.x << ',' << p1.y << " - "
                    << p2.x << ',' << p2.y << " - "
                    << p3.x << ',' << p3.y << " - "
                    << p4.x << ','<< p4.y << 
                    " size=" << dx*dx+dy*dy << endl;
*/
                // 面積は三平方の定理から
                max_size = max(max_size, dx*dx+dy*dy);
            }
        }
    }

    cout << max_size << endl;
    return 0;
}
