#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

#define y first
#define x second
int H,W,K;
vector<string> S(13);
vector<vector<bool>> visited;
stack<pair<int,int>> goal_path;
int ans = 0;

// 深さ優先探索
void dfs(pair<int,int> pos, int depth)
{
    //cout << "y=" << pos.y << " x=" << pos.x << endl;

    // 訪問済みなら再帰コールしないようにしているのでこの行は不要。念のため。
    if (visited[pos.y][pos.x]) return;

    if (depth == 0) {
        ans++;
        return;
    }

    vector<pair<int,int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
    for (auto next : direction) {  // 上下左右を調べる
        int next_y = pos.y + next.y;
        int next_x = pos.x + next.x;
        if (S[next_y][next_x] != '.') continue; // 通路でなければ進めない
        if (visited[next_y][next_x]) continue; // nextが探索済だったらスルー
        visited[pos.y][pos.x] = true;  // 訪問済フラグを立てる
        dfs(make_pair(next_y,next_x), depth-1);  // 再帰的に探索
        visited[pos.y][pos.x] = false;  // 訪問済フラグを立てる
    }
}
 
int main()
{
    // 入力
    cin >> H >> W >> K;
    rep(i,H) cin >>S[i];
 
    // 周囲を壁で囲む
    S.insert(S.begin(), string(W+2, '#'));
    range(y,1,H) S[y] = "#" + S[y] + "#";
    S.push_back(string(W+2, '#'));
 
    // 探索
    range(y,1,H) range(x,1,W) {
        // フラグ初期化
        visited = vector<vector<bool>>(H+2, vector<bool>(W+2, false));

        pair<int,int> start = {y,x};
        if (S[y][x] != '.') continue;
        //cout << "Start: y=" << y << " x=" << x << endl;
        dfs(start, K);
        //cout << "ans=" << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

/*
3 3 3
.#.
...
#..

y=0 x=0 ans=2
y=0 x=2 ans=3 (x)
y=1 x=0 ans=3 (x)
y=1 x=1 ans=1
y=1 x=2 ans=2
y=2 x=1 ans=3
y=2 x=2 ans=2
*/