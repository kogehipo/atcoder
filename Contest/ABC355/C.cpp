#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int N,T;
    cin >> N >> T;
    vector<int> A(T);
    rep(i, T) {
        cin >> A[i];
        A[i]--;
    }

    vector<set<int>> X(N*2+2);
    int i = 0;
    for (i=0; i<N; i++) rep(j,N) X[i].insert(i*N+j);
    for (   ; i<N*2; i++) rep(j,N) X[i].insert(j*N+(i-N));
    rep(i,N) X[N*2].insert(i*N+i);
    rep(i,N) X[N*2+1].insert((i+1)*N-i-1);
/*
    rep(i, N*2+2) {
        for (auto itr=X[i].begin(); itr!=X[i].end(); itr++) cout << *itr << ' ';
        cout << endl;
    }
*/
    rep(i, T) {
/*
        rep(j, N*2+2) {
            X[j].erase(A[i]);
            if (X[j].empty()) {
                cout << i+1 << endl;
                return 0;
            }
        }
*/
        int j = A[i]/N;
        X[j].erase(A[i]);
        if (X[j].empty()) {
            cout << i+1 << endl;
            return 0;
        }
        j = N + A[i]%N;
        X[j].erase(A[i]);
        if (X[j].empty()) {
            cout << i+1 << endl;
            return 0;
        }
        X[N*2].erase(A[i]);
        if (X[N*2].empty()) {
            cout << i+1 << endl;
            return 0;
        }
        X[N*2+1].erase(A[i]);
        if (X[N*2+1].empty()) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
