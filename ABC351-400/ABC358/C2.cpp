#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7FFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int N,M;
vector<string> S;
int ans = INF;

void check(vector<bool> choice) {
    vector<bool> OR(M, false);
    rep(i, N) {
        if (choice[i]) {
            rep(j, M) if (S[i][j] == 'o') OR[j] = true;
        }
    }
    rep(j, M) if (!OR[j]) return;
    ans = min(ans, (int)ranges::count(choice, true));
}

void f(int n, vector<bool> choice) {
    vector<bool> C(N);
    C = choice;
/*
    cout << "n=" << n << " ";
    rep(i,N) {
        if (C[i]) cout << "1";
        else cout << "0";
    } 
    cout << endl;
*/
    if (n == N-1) {
        check(C);
        C[n] = !C[n];
        check(C);
        return;
    }
    f(n+1, C);
    C[n] = !C[n];
    f(n+1, C);
}

int main()
{
    cin >>N>>M;
    S.resize(N); rep(i,N) cin >>S[i];
    vector<bool> choice(N, false);
    f(0, choice);
    cout << ans << endl;
    return 0;
}
