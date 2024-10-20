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
    int N; cin >>N;
    string S,T; cin >>S>>T;
    S = S + "..";
    T = T + "..";

    queue<string> Q;
    Q.push(S);
    map<string, int> D; // その文字列への距離
    D[S] = 0;

    while (!Q.empty()) {

        string s = Q.front(); Q.pop();  // 調べる文字列
        int dist = D[s];  // その文字列への距離

        // 空白を探す
        int sp = 0;
        while (s[sp] != '.') sp++;

        rep(i, N+1) {
            if (s[i] != '.' && s[i+1] != '.') {
                string tmp = s;
                swap(tmp[i], tmp[sp]);
                swap(tmp[i+1], tmp[sp+1]);
                if (D.find(tmp) != D.end()) continue;  // すでに調査済み
                Q.push(tmp);
                D[tmp] = dist + 1;
            }
        }
    }
    if (D.find(T) == D.end()) cout << -1 << endl;
    else cout << D[T] << endl;
    return 0;
}
