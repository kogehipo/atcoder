#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define coutf cout << fixed << setprecision(8)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

#define swap(a,b) {int tmp = a; a = b; b = tmp;}

int main()
{
    int T; cin >>T;
    int N; cin >>N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    int M; cin >>M;
    vector<int> B(M); rep(i, M) cin >> B[i];
    int t = 0;  // 時刻
    int n = 0;  // A(焼き上がり)の添字
    int m = 0;  // B(来店)の添字
    queue<int> q;
    while(m < M) {
        if (N <= n) {
            t = B[m];
        } else {
            t = min(A[n], B[m]);
        }
        if (t == A[n]) {  // たこ焼きが焼けた
            q.push(A[n]);
            n++;
            continue;
        }
        // 客が来た
        while(1) {
            if (q.empty()) {  // たこ焼きがない
                cout << "no" << endl;
                return 0;
            } else if (q.front() + T < B[m]) {
                q.pop();  // 古いたこ焼きを捨てる
                continue;
            } else {
                q.pop();  // おししいたこ焼きを売る
                break;
            }
        }
        m++;
    }
    cout << "yes" << endl;
    return 0;
}
