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

int N,K;
string S;
set<string> st;
void makeset(string a, string b) {
    if (b.size() == 0) {
        st.insert(a);
        return;
    }
    rep(i,b.size()) {
        string c = a+b[i];
        string d = b.substr(0,i) + b.substr(i+1);
        makeset(c, d);
    }
}

bool kaibun(string s,int l,int r) {
    int m = (r-l+1)/2;
    rep(i,m) {
        if (s[l+i] != s[r-i]) return false;
    }
    return true;
}

int main()
{
    cin >>N>>K;
    cin >>S;

    makeset("", S);
    int ans = st.size();
    for (auto s : st) {
        //cout << s << endl;
        rep(l,N) {
            int r = l+K-1;
            if (N <= r) break;
            if (kaibun(s,l,r)) {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
