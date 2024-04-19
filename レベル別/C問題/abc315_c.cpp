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
    int N;
    cin >> N;
    vector<pair<int,int>> F(N);  // 味,美味しさ のペア
    vector<pair<int,int>> S(N);  // 美味しさ,味 のペア
    rep(i, N) {
        int f, s;
        cin >> f >> s;
        F[i].first = f;
        F[i].second = s;
        S[i].first = s;
        S[i].second = f;
    }

    // 味の順に逆ソート
    sort(rall(F));
    ll f = 0;
    ll prev = -1;
    rep(i, N) {
        if (i != prev &&   // 新しい味で、
            i < N-1 &&    // 最後ではなくて、 
            F[i].first == F[i+1].first) {  // 次の味も同じなら
            ll tmp = F[i].second + F[i+1].second/2;
            f = max(f, tmp);
            prev = i;
        }
    }

    // 美味しさの順に逆ソート
    sort(rall(S));
    ll s = S[0].first;
    ll flavor = S[0].second;
    int i = 1;
    while(i < N && S[i].second == flavor) i++;
    s += S[i].first;

    if (f < s) cout << s << endl;
    else cout << f << endl;
    return 0;
}
