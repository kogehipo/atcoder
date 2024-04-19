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
    int H, W;
    cin >> H >> W;
    map<string, int> mp;
    rep(i, H) {
        string S;
        cin >> S;
        mp[S] = i+1;
    }

    // mapをpairのvectorに変換
    vector<pair<string, int>> p;
    for(auto a : mp) p.push_back(make_pair(a.first, a.second));

    int eaten_line = -1; int eaten_cookie_count = 0;
    int full_line = -1;  int full_cookie_count = 0;
    rep(i, p.size()) {
        int count = std::count(all(p[i].first), '#');
        if (count == 0) {  // クッキーの行ではない
            continue;
        } else if (count != 0 && full_line == -1) {  // クッキーがある行が出てきた
            full_line = i;
            full_cookie_count = count;
        } else if (count == full_cookie_count) {  // 2行目以降のクッキー行
            continue;
        } else {
            eaten_line = i;
            eaten_cookie_count = count;
            if (full_cookie_count < eaten_cookie_count) {
                swap(full_cookie_count, eaten_cookie_count);
                swap(full_line, eaten_line);
                break;
            }
        }
    }
    cout << p[eaten_line].second << ' ';
    rep(i, p[eaten_line].first.size()) {
        if (p[eaten_line].first[i] != p[full_line].first[i]) {
            cout << i+1 << endl;
        }
    }
    return 0;
}
