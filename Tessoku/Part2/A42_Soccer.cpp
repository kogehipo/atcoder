#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ap
// 解説 


int main()
{
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> V(N);
    rep(n, N) cin >> V[n].first >> V[n].second;

    int ans = 0;
    for (int a=0; a<=100; a++) {
        for(int b=0; b<=100; b++) {
            int count = 0;
            rep(n, N) {
                if (a <= V[n].first  && V[n].first  <= a+K  &&
                    b <= V[n].second && V[n].second <= b+K) count++;
            }
            ans = max(ans, count);
        }
    }
    cout << ans << endl;
    return 0;
}
