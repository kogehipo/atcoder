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

// 要素数3以上のmin/max（C++20から）例.min({1,2,3})
//#define min std::ranges::min
//#define max std::ranges::max

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

int main()
{
    int N,M; cin >>N>>M;
    vector<pair<int,int>> A(N);
    rep(i,N) { cin >>A[i].first; A[i].second = i; }
    vector<pair<int,pair<int,int>>> B(M);
    rep(i,M) { cin >>B[i].first; B[i].second.first = i; B[i].second.second = -2; }
    sort(all(A));  // 美食家の順
    sort(rall(B));  // おいしい順

    cout << "--\n";
    rep(a,N) cout << A[a].first << "(" << A[a].second << ") "; cout << endl;
    rep(b,M) cout << B[b].first << "(" << B[b].second.first << ") ";  cout << endl;
    cout << "--\n";

    int a = 0;
    int b = 0;
    while(1) {
        if (a == N || b == M) {
            break;
        } else if (A[a].first <= B[b].first) { // 料理が十分おいしい
            B[b].second.second = A[a].second;  // この料理bは美食家aが取る、次の料理をチェック
            b++;
        } else {  // 料理がまずいので次の美食家にチェックしてもらう
            a++;
        }
    }
rep(b,M) cout << B[b].first << " " << B[b].second.first << " " << B[b].second.second << endl; 
    rep(b,M) swap(B[b].first, B[b].second.first);
    sort(all(B));
    rep(b,M) cout << B[b].second.second+1 << endl;
    return 0;
}
