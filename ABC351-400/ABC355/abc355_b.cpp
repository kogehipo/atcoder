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
    vector<int> C;
    vector<int> A(N); rep(i,N) {cin >>A[i]; C.push_back(A[i]);}
    vector<int> B(M); rep(i,M) {cin >>B[i]; C.push_back(B[i]);}
    sort(all(A));
    sort(all(B));
    sort(all(C));
    int a=0, c=0;
    while (C[c] != A[a]) c++;
    while (a<N-1 && c<M+N-1) {
        if (A[a] == C[c] && A[a+1] == C[c+1]) {
            cout << "Yes" << endl;
            return 0;
        }
        a+=1;
        while (C[c] != A[a]) c++;
    }
    cout << "No" << endl;
    return 0;
}
