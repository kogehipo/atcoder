#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 
// 解説 


int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    rep(n, N) cin >> A[n];

    rep(i, N-1) {

        rep(j, N) cout << A[j] << ' ';
        cout << endl;

        if (A[i] == A[i+1]+1 || A[i] == A[i+1]-1) continue;

        if (A[i] < A[i+1]) {
            int M = A[i+1]-A[i]-1;
            rep(j, M) A.insert(A.begin()+i+j+1, A[i]+j+1);
            N += M;
            i += M;
        }

        else {
            int M = A[i]-A[i+1]-1;
            rep(j, M) A.insert(A.begin()+i+j+1, A[i]-j-1);
            N += M;
            i += M;
        }
    }

    rep(i, N) {
        if (i != 0) cout << ' ';
        cout << A[i];
    }
    cout << endl;
    return 0;
}
