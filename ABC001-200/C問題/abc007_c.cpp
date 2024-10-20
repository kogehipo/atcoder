#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

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
    int sy,sx,gy,gx; cin >>sy>>sx>>gy>>gx;
    sy--; sx--; gy--; gx--;
    vector<string> A(R); rep(i,R) cin >> A[i];

    using Graph = vector<vector<int>>;
    Graph G(R*C);
    rep(i,R*C) {
        int y = i/C;
        int x = i%C;
        if (A[y][x] == '#') continue;
        if (y < R-1 && A[y+1][x] != '#') { G[i].push_back(i+C); G[i+C].push_back(i); }
        if (x < C-1 && A[y][x+1] != '#') { G[i].push_back(i+1); G[i+1].push_back(i);   }
    }
/*
    rep(i,R*C) {
        cout << "G=" << i << endl;
        rep(j,G[i].size()) cout << G[i][j] << " ";
        cout << endl;
    }
*/
    int i = sy*C+sx;
    int goal = gy*C+gx;
    queue<int> Q;
    Q.push(i);
    vector<int> D(R*C, -1);  // 始点からの距離（訪問フラグを兼用）
    D[i] = 0;

    while(!Q.empty()) {
        i = Q.front(); Q.pop();
        if (i == goal) {  // ゴール到着
            cout << D[i] << endl;
/*
            rep(y,R) {
                rep(x,C) cout << D[y*C+x] << " ";
                cout << endl;
            }
*/
            return 0;
        }
        for (int j : G[i]) {
            if (D[j] == -1) {
                D[j] = D[i] + 1;
                Q.push(j);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
