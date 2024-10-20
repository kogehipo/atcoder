#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
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
// 問題 
// 解説 


int main()
{
    int N;
    cin >> N;
    vector<vector<int>> G(N);

    rep(i, N) {
        rep(j, N) {
            int a;
            cin >> a;
            if (a==1) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
/*
    rep(i, N) {
        for (int j=0; j<G[i].size(); j++) {
            cout << G[i][j];
        }
        cout << endl;
    }
return 0;
*/
    rep(i, N) {
        sort(G[i].begin(), G[i].end());
        int lastone = -1;
        bool needspace = false;
        for (int j=0; j<G[i].size(); j++) {
            if (G[i][j] != lastone) {
                if (needspace) cout << ' ';
                else needspace = true;
                cout << G[i][j]+1;
                lastone = G[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
