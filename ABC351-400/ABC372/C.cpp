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

int count(string S)
{
    int ans = 0;
    int i = 0;
    while(i<S.size()-2) {
        if (S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') {
            ans++;
            i += 3;
            continue;
        } else {
            i++;
        }
    }
    return ans;
}

int main()
{
    int N,Q; cin >>N>>Q;
    string S; cin >>S;
    vector<int> X(Q);
    vector<char> C(Q);
    rep(i,Q) cin >>X[i]>>C[i];

    int ans = count(S);

    rep(i,Q) {
        int j = X[i]-1;
        if      (        S[j  ] == 'A' && S[j+1] == 'B' && S[j+2] == 'C' && C[i] != 'A' ) ans--;
        else if ( 0<j && S[j-1] == 'A' && S[j  ] == 'B' && S[j+1] == 'C' && C[i] != 'B' ) ans--;
        else if ( 1<j && S[j-2] == 'A' && S[j-1] == 'B' && S[j  ] == 'C' && C[i] != 'C' ) ans--;

        if      (j < S.size()-2 && S[j] != 'A' && C[i] == 'A' && S[j+1] == 'B' && S[j+2] == 'C' ) ans++;
        else if (j < S.size()-1 && S[j] != 'B' && C[i] == 'B' && S[j-1] == 'A' && S[j+1] == 'C' ) ans++;
        else if (j < S.size()   && S[j] != 'C' && C[i] == 'C' && S[j-2] == 'A' && S[j-1] == 'B' ) ans++;
        S[j] = C[i]; 
        cout << ans << endl;
    }
    return 0;
}
