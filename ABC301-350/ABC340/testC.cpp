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


/*
ll pay(ll x) {
    if (x == 1) return 0L; 
    ll a = x/2;
    ll b = (x+1)/2;
    return x + pay(a) + pay(b);
}
*/


map<ll, ll> mp;

ll pay(ll x) {
    if (x == 1) return 0L; 

    ll a, b, A, B;

    a = x/2;
    b = (x+1)/2;

    auto ia = mp.find(a);
    if (ia == mp.end()) {
        A = pay(a);
        mp[a] = A;
    } else {
        A = ia->second;
    }

    auto ib = mp.find(b);
    if (ib == mp.end()) {
        B = pay(b);
        mp[b] = B;
    } else {
        B = ib->second;
    }

    return x + A + B;
}


int main()
{
    ll N;
    cin >> N;
    cout << pay(N) << endl;
    return 0;
}
