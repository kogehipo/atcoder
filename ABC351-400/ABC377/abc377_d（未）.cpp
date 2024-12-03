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
    int N,M; cin>>N>>M;
    //vector<int> L(N), R(N);
    //rep(i,N) cin>>L[i]>>R[i];
    vector<pair<int,int>> data(N);
    rep(i,N) cin>>data[i].first>>data[i].second;

    ll ans = 0;

    vector<pair<int,int>> A;
    A = data;
    sort(all(A));

    cout << "-" << endl;
    rep(i,N) cout << A[i].first << " " << A[i].second << endl;
    cout << "-" << endl;

    rep(i,N) {
        range(j,i+1,N-1) {
            if (A[i].first == A[j].first) {
                int x = min(A[i].second, A[j].second);
                A[i].second = A[j].second = x;
            }
            if (A[i].second <= A[j].first) break;
            if (A[j].second < A[i].second) A[i].second = A[j].second;
        }
        ans += min(M, (A[i].second - A[i].first));
        //cout << i << " " << ans << " " << (A[i].second- A[i].first) << endl;
    }

    A = data;
    rep(i,N) swap(A[i].first, A[i].second);
    sort(all(A));
    rep(i,N) swap(A[i].first, A[i].second);

    rep(i,N) {
        int j;
        for (j=i+1; j<=N-1; j++) {
            //if (A[i].first == A[j].first) {
            //    int x = min(A[i].second, A[j].second);
            //    A[i].second = A[j].second = x;
            //}
            if (A[i].second <= A[j].first) break;
            //if (A[j].second < A[i].second) A[i].second = A[j].second;
        }
        ans += min(M, (A[j].first - A[i].second));
        //cout << i << " " << ans << " " << (A[i].second- A[i].first) << endl;
    }

    cout << ans << endl;
    return 0;
}
