#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

bool isKaibun(string S, int l, int len) {
    for (int i=l; i<l+len/2; i++) {
        if (S[i] != S[l+len-1-(i-l)]) return false;
    }
    return true;
}

int main()
{
    string S; cin>>S;
    int N = S.size();
    for (int len=N; len>0; len--) {  // len=回分の長さ
        range(l,0,N-len) {
            if (isKaibun(S,l,len)) { 
                cout << len << endl;
                return 0;
            }
        }
    }
}
