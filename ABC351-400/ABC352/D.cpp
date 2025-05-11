#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

#define fromto(a,from,to) a.begin()+from, a.begin()+to+1

int main()
{
    int N,K; cin>>N>>K;
    vector<int> A(N,-1);
    rep(i, N) {
        int a; cin >> a;
        A[a-1] = i;  // aが現れたインデックス
    }

    multiset<int> mst;
    rep(i,K) mst.insert(A[i]);
    int ans = *mst.rbegin() - *mst.begin();

    // 区間をずらしながら検査する
    range(i,1,N-K) {
        mst.erase(A[i-1]);
        mst.insert(A[i+K-1]);
        ans = min(ans, *mst.rbegin() - *mst.begin());
    }
    cout << ans << endl;
    return 0;
}
