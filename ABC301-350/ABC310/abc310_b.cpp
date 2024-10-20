#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define coutf cout << fixed << setprecision(8)
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))

// 要素数3以上のmin/max（C++20から）
#define min std::ranges::min
#define max std::ranges::max

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

int is_better(vector<int> cheap, vector<int> expensive)
{
    if (cheap == expensive) return 0;
    if (cheap.size() < expensive.size()) return -1;
    bool additional_function = false;
    int c = 0;
    for (int e=0; e<expensive.size(); e++) {
        if (cheap.size() <= c) return -1;
        if (cheap[c] == expensive[e]) {
            c++;
            continue;
        } 
        additional_function = true;
        while(cheap[c] != expensive[e]) {
            c++;
            if (c == cheap.size()) return -1;
        }
        c++;
    }
    if (additional_function) return 1;
    return 0;
}


int main()
{
    int N,M; cin >>N>>M;
    vector<pair<int,vector<int>>> P(N);
    rep(i,N) {
        cin >> P[i].first;
        int c; cin >> c;
        rep(j,c) {
            int x; cin >> x;
            P[i].second.push_back(x);
        }
    }
    rep(i,N) sort(all(P[i].second));

    rep(i,N) rep(j,N) {
        if (i==j) continue;
        if (P[i].first < P[j].first) continue;
        // 低価格なjが、iより高機能であるか調べる
        int check = is_better(P[j].second, P[i].second);
        if (check < 0) continue;
        if (check == 0 && P[j].first < P[i].first ||
            check == 1) {
            cout << "Yes" << endl;
            return 0;
        } 
    }
    cout << "No" << endl;
    return 0;
}
