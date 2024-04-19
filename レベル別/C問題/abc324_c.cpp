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

// この回答でも正答であるが、もっと賢いやり方がある。解説を参照。


int main()
{
    int N;
    cin >> N;
    string T;
    cin >> T;
    int Tsize = T.size();
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    int ans = 0;
    vector<int> ansList;
    rep(i, N) {
        int Ssize = S[i].size();
        if (Ssize == Tsize) {
            int diff = 0;
            rep(j, Tsize) if (S[i][j] != T[j]) diff++;
            if (diff <= 1) {
                ansList.push_back(i+1);
                ans++;
            }
        }
        else if (Ssize == Tsize-1) {
            int diff = 0;
            rep(j, Ssize) if (S[i][j] != T[j+diff]) {
                diff++;
                if (S[i][j] != T[j+diff]) diff++;
                if (diff > 1) break;
            }
            if (diff <= 1) {
                ansList.push_back(i+1);
                ans++;
            }
        }
        else if (Ssize-1 == Tsize) {
            int diff = 0;
            rep(j, Tsize) if (T[j] != S[i][j+diff]) {
                diff++;
                if (T[j] != S[i][j+diff]) diff++;
                if (diff > 1) break;
            }
            if (diff <= 1) {
                ansList.push_back(i+1);
                ans++;
            }
        }
    }
    cout << ans << endl;
    rep(i, ansList.size()) {
        if (i!=0) cout << ' ';
        cout << ansList[i];
    }
    cout << endl;
    return 0;
}
