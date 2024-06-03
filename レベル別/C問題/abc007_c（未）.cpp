#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define coutf cout << fixed << setprecision(8)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

#define swap(a,b) {int tmp = a; a = b; b = tmp;}

struct Point { int y, x; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}
bool operator==(const Point &p1, const Point &p2){
    return (p1.y == p2.y && p1.x == p2.x);
}

int main()
{
    int R,C; cin >>R>>C;
    Point S, G;
    cin >> S.y >> S.x;
    cin >> G.y >> G.x;
    S.x--; S.y--; G.x--; G.y--;
    vector<string> c(R);
    rep(i,R) cin >> c[i];
    int ans = 0;
    Point p = S;
    queue<Point> que;
    que.push(p);
    while(1) {
        while(!que.empty()) {
            p = q.front();
            q.pop();
            if (p == G) {  // ゴールに到着
                cout << ans << endl;
                return 0;
            }
            int x = p.x, y = p.y;
            if (c[y][x] == '#') continue;
            c[y][x] = '#';
            if (x > 0   && c[y][x-1] == '.') que.push({y,x-1});
            if (x < C-1 && c[y][x+1] == '.') que.push({y,x+1});
            if (y > 0   && c[y-1][x] == '.') que.push({y-1,x});
            if (y < R-1 && c[y+1][x] == '.') que.push({y+1,x});
        }
        ans++;  // 手数をひとつ進める
    }
    cout << -1 << endl;
    return 0;
}
