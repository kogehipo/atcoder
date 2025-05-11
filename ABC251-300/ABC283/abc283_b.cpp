#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc283/tasks/abc283_b
// 解説 


int main()
{
    // 整数の数と、正数列を読み込む
    int N; cin >> N;
    vector<int> A;
    rep(i, 0, N) {
        int a; cin >> a;
        A.push_back(a);
    }

    // クエリーの数
    int Q; cin >> Q;

    // クエリーをひとつずつ処理
    rep (q, 0, Q) {
        int query; cin >> query;
        int k; cin >> k;
        if (query == 1) {
            int x; cin >> x;
            A[k-1] = x;
        }
        else {
            cout << A[k-1] << endl;
        }
    }

    return 0;
}
