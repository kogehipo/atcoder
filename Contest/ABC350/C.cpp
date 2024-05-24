#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

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
    int N;
    cin >> N;
    vector<int> A(N+1, -1);
    vector<int> R(N+1, -1);  // R[i] = Aのiの位置
    range(i, 1, N) {
        cin >> A[i];
        R[A[i]] = i;
    }

//    i : 1 2 3 4 5
//  A[i]: 3 4 1 2 5
//  R[i]: 3 4 1 2 5

    vector<pair<int,int>> ans;
    range(i, 1, N) {
        if (A[i] == i) continue;
        int j = R[i];
        R[A[i]] = j;
        swap(A[i], A[j]);
        ans.push_back(make_pair(i, j));
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}
