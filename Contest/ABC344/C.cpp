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
    int N, M, L, Q;
    cin >> N;
    vector<int> A(N);
    rep(n, N) cin >> A[n];
    cin >> M;
    vector<int> B(M);
    rep(m, M) cin >> B[m];
    cin >> L;
    vector<int> C(L);
    rep(l, L) cin >> C[l];
    cin >> Q;
    vector<int> X(Q);
    rep(q, Q) cin >> X[q];

    vector<int> T;
    rep(a, N) {
        rep(b, M) {
            rep(c, L) {
                T.push_back(A[a]+B[b]+C[c]);
            }
        }
    }

    sort(T.begin(), T.end());

    rep(i, Q) {
        auto itr = lower_bound(T.begin(), T.end(), X[i]);
        if (itr == T.end()) {
            cout << "No" << endl;
        }
        else if (T[itr-T.begin()] == X[i]) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
