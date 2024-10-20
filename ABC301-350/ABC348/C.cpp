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
    vector<int> A(N), C(N);
    rep(i, N) cin >> A[i] >> C[i];

    map<int,int> mp;
    rep(i, N) {
        if (mp.find(C[i]) == mp.end()) {
            mp[C[i]] = A[i];
        } else {
            if (A[i] < mp[C[i]]) mp[C[i]] = A[i];
        }
    }

    int ans = 0;
    for (const auto& item : mp) {
        if (ans < item.second) ans = item.second;
    }
    cout << ans << endl;
    return 0;
}
/*


    vector<int> iro;
    vector<int> taste;
    rep(i, N) {
//cout << i << ' ';
        auto it = find(all(iro), C[i]);
        if (it == iro.end()) {
//cout << "(a)" << C[i] << ' ' << A[i] << endl;
            iro.push_back(C[i]);
            taste.push_back(A[i]);
        } else {
            int k = it - iro.begin();
            if (A[i] < taste[k]) taste[k] = A[i];
//cout << "(b)" << C[i] << ' ' << taste[k] << endl;
        }
    }

    auto it = max_element(all(taste));
    cout << *it << endl;
    return 0;
}
*/