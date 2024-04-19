#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    rep(i, M) cin >> A[i];
    sort(all(A));

    // N日分のリストを作成
    vector<int> X(N, 0);
    // 花火があれば1にする
    int j = 0;
    rep(i, N) {
        if (A[j] == i+1) {
            X[i] = 1;
            j++;
        }
    }

    int next = 0;
    for(int i=N-1; 0<=i; i--) {
        if (X[i] == 1) next = 0;
        else next++;
        X[i] = next;
    }

    rep(i, N) cout << X[i] << endl;
    return 0;
}
