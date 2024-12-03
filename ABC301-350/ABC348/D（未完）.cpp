#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
 
#define y first
#define x second
int H,W,N;
vector<string> S;
vector<vector<bool>> visited;
stack<pair<pair<int,int>,int>> goal_path;
map<pair<int,int>,int> energy_list;
pair<int,int> start;
pair<int,int> goal;
int energy = 0;

// 深さ優先探索
bool dfs(pair<int,int> pos)
{
    //cout << "DFS: y=" << pos.y << " x=" << pos.x << endl;
    int old_energy = energy;

    if (energy-1 < energy_list[pos]) {
        energy = energy_list[pos];
        if (energy < 1) {
            //cout << "Energy is empty!" << endl;
            energy = old_energy;
            return false;
        }
    }

    vector<pair<int,int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
    for (auto next : direction) {  // 上下左右を調べる
        int next_y = pos.y + next.y;
        int next_x = pos.x + next.x;
        if (next_x == goal.x && next_y == goal.y) {
            //cout << "Goal reached!" << endl;
            goal_path.push({goal,energy});
            return true;
        }
        else {
            //cout << "  next: next_y=" << next_y << " next_x=" << next_x << endl;
            if (S[next_y][next_x] == '#') continue; // 通路でなければ進めない
            if (visited[next_y][next_x]) continue; // nextが探索済だったらスルー
            visited[pos.y][pos.x] = true;  // 今の場所に訪問済フラグを立てておく
            energy--;
            bool res = dfs(make_pair(next_y,next_x));  // 再帰的に探索
            energy++;
            visited[pos.y][pos.x] = false;  // 今の場所の訪問済フラグをクリア
            if (res) {
                goal_path.push({make_pair(next_y,next_x),energy});
                return true;
            }
        }
    }
    energy = old_energy;
    return false;
}
 
int main()
{
    // 入力
    cin >> H >> W;
    S.resize(H);
    rep(i,H) cin >>S[i];
    cin >> N;
    rep(i,N) {
        int y,x,p;
        cin >> y >> x >> p;
        energy_list[{y,x}] = p;
    }

    // 迷路の周囲を壁で囲む
    S.insert(S.begin(), string(W+2, '#'));
    range(y,1,H) S[y] = "#" + S[y] + "#";
    S.push_back(string(W+2, '#'));
 
    // フラグ初期化
    visited.assign(H+2, vector<bool>(W+2, false));

    // スタート・ゴールを決める
    range(y,1,H) range(x,1,W) {
        if (S[y][x] == 'S') start = {y,x};
        if (S[y][x] == 'T') goal = {y,x};
    }

    // 探索
    energy = 0;
    bool res = dfs(start);
/*
    // ゴールまでの経路を結果出力
    cout << "y=" << start.y << " x=" << start.x << endl;
    while(!goal_path.empty()) {
        pair<pair<int,int>,int> p = goal_path.top();
        goal_path.pop();
        cout << "y=" << p.first.y << " x=" << p.first.x << " e=" << p.second << endl;
    }
*/

    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}