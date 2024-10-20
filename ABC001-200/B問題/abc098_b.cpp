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

// 要素数3以上のmin/max（C++20から）
#define min std::ranges::min
#define max std::ranges::max

int main()
{
    int N; cin >>N;
    string S; cin >>S;
    int ans = 0;
    range(i,1,N-1) {
        set<char> s1, s2;
        for (int j = 0; j < i; j++) s1.insert(S[j]);
        for (int j = i; j < N; j++) s2.insert(S[j]);
        int cnt = 0;
        for (auto c : s1) if (s2.count(c)) cnt++;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
