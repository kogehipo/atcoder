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
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N , 0);
    map<ll,ll> m;
    m[0] = N;
    ll ans = 1;
    rep(t, T) {
        ll a, b;
        cin >> a >> b;
        ll oldA = A[a-1];
        ll newA = A[a-1]+b;
        A[a-1] = newA;
        m[oldA]--;
        if (m[oldA] == 0) m.erase(oldA);
        m[newA]++;
        cout << m.size() << endl;
    }
    return 0;
}
