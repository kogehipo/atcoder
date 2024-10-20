#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

// ここから下はオプション。問題によって選択すること。

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}

//---------------------------------------------------
// 問題 
// 解説 

int H, W;
vector<string> A(201);
pair<int,int> S, T;
int N;
vector<pair<int,int>> RC;
vector<int> E;

bool f(pair<int,int> pos, int energy) {
    if (pos == T) return true;  // ゴール到達
    //cout << '(' << pos.first << ',' << pos.second << ") " << energy << endl;
    if (A[pos.first][pos.second] != 'S' &&
        A[pos.first][pos.second] != '.') { return false; }
    //else cout << "--" << endl;

    int bakE = 0;
    auto a = find(all(RC), pos);
    if (a != RC.end()) {
        bakE = E[a - RC.begin()];
        if (energy < backE) {
            energy = backE;
        }
    }
    if (energy == 0) return false;

    char bakPos = A[pos.first][pos.second];
    A[pos.first][pos.second] = '*';
    pair<int,int> u = pos; u.first--;
    pair<int,int> d = pos; d.first++;
    pair<int,int> l = pos; l.second--;
    pair<int,int> r = pos; r.second++;
    if (0 <= u.first ) if(f(u, energy-1)) return true;  
    if (d.first < H  ) if(f(d, energy-1)) return true;  
    if (0 <= l.second) if(f(l, energy-1)) return true;  
    if (r.second < W ) if(f(r, energy-1)) return true;  
    A[pos.first][pos.second] = bakPos;

    auto a = find(all(RC), pos);

    return false;
}

int main()
{
    cin >> H >> W;
    rep(i, H) {
        cin >> A[i];
        int res = A[i].find("S");
        if (res != string::npos) { S.second = (int)res; S.first = i; }
        res = A[i].find("T");
        if (res != string::npos) { T.second = (int)res; T.first = i; }
    }
    //cout << S.first << S.second << "->" << T.first << T.second << endl;

    cin >> N;
    rep(i, N) {
        pair<int,int> a;
        int e;
        cin >> a.first >> a.second >> e;
        a.first--;
        a.second--;
        RC.push_back(a);
        E.push_back(e);
    }

    if (f(S,0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
