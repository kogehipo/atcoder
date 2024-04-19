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


int main()
{
    int N;
    cin >> N;

    vector<int> count(N, 0);  // 出てきた回数をカウント
    vector<pair<int,int>> ans(N);    // ２回目に出てきたときのインデックスを格納
    rep(i, N) { ans[i].first = 0; ans[i].second = i+1; }

    rep(i, N*3) {
        int a;
        cin >> a;
        count[a-1]++;
        if (count[a-1] == 2) ans[a-1].first = i;
    }
    sort(all(ans));
    for (auto a : ans) cout << a.second << " ";
    cout << endl;
    return 0;
}
