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

ll min(long long rep[]) {
    ll min = 0;
    for (ll i=1; i<3; i++) {
        if (rep[i] < rep[min]) {
            min = i;
        }
    }
    return min;
}

void reset(ll rep[], ll a) {
    ll val = rep[a];
    rep(i, 3) {
        if (i == a) continue;
        if (rep[i] < val) rep[i] = 1;
    }
}

int main()
{
    ll N;
    cin >> N;

    long long rep[3] = {1, 1, 1};

    for (ll i=1; i<N; i++) {
        ll a = min(rep);
        if (rep[a] == 1) {
            rep[a] = 11;
            reset(rep, a);
        } else if (rep[a] == 11) {
            rep[a] = 111;
            reset(rep, a);
        } else if (rep[a] == 111) {
            rep[a] = 1111;
            reset(rep, a);
        } else if (rep[a] == 1111) {
            rep[a] = 11111;
            reset(rep, a);
        } else if (rep[a] == 11111) {
            rep[a] = 111111;
            reset(rep, a);
        } else if (rep[a] == 111111) {
            rep[a] = 1111111;
            reset(rep, a);
        } else if (rep[a] == 1111111) {
            rep[a] = 11111111;
            reset(rep, a);
        } else if (rep[a] == 11111111) {
            rep[a] = 111111111;
            reset(rep, a);
        } else if (rep[a] == 111111111) {
            rep[a] = 1111111111;
            reset(rep, a);
        } else if (rep[a] == 1111111111) {
            rep[a] = 11111111111;
            reset(rep, a);
        } else if (rep[a] == 11111111111) {
            rep[a] = 111111111111;
            reset(rep, a);
        } else if (rep[a] == 111111111111) {
            rep[a] = 1111111111111;
            reset(rep, a);
        }
    }

    cout << rep[0] << ' ' << rep[1] << ' ' << rep[2] << endl;
    cout << rep[0] + rep[1] + rep[2] << endl;
    return 0;
}
