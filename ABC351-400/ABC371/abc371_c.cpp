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

int main()
{
    int N; std::cin >>N;
    int M;
    vector<vector<int>> G(N, vector<int>(N,0));  // N=頂点数
    vector<vector<int>> H(N, vector<int>(N,0));  // N=頂点数
    cin >>M;
    rep(m,M) {   // 辺の数だけループ
        int a, b;
        cin >> a >> b;
        G[a-1][b-1] = G[b-1][a-1] = 1;  // 辺あり
    }
    cin >>M;
    rep(m,M) {   // 辺の数だけループ
        int a, b;
        cin >> a >> b;
        H[a-1][b-1] = H[b-1][a-1] = 1;  // 辺あり
    }
    // コストの表
    vector<vector<int>> A(N, vector<int>(N, 0));
    rep(i,N-1) {
        range(j,i+1,N-1) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }
/*
    rep(i,N) {
        cout << "G: ";
        rep(j,N) cout << G[i][j] << " ";
        cout << endl;
    }
    rep(i,N) {
        cout << "H: ";
        rep(j,N) cout << H[i][j] << " ";
        cout << endl;
    }
    rep(i,N) {
        cout << "A: ";
        rep(j,N) cout << A[i][j] << " ";
        cout << endl;
    }
*/
    int ans = INF;
    vector<int> P;
    rep(i,N) P.push_back(i);
    do {
        //rep(z,N) cout << P[z] << " ";
        //cout << " - ";
        int tmpAns = 0;
        range(a,0,N-2) range(b,a+1,N-1) {
            if (G[a][b] != H[P[a]][P[b]]) {
                tmpAns += A[P[a]][P[b]];
                //cout << A[P[a]][P[b]] << " ";
            }
            //else cout << "* ";
        }
        //cout << "tmpAns=" << tmpAns << endl;
        ans = min(ans, tmpAns);
    } while (next_permutation(P.begin(), P.end()));
    cout << ans << endl;
    return 0;
}
