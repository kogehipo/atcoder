#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
// 要素数3以上のmin/max（C++20から）例.min({1,2,3})
//#define min std::ranges::min
//#define max std::ranges::max

int main()
{
    int N; cin >>N;
    vector<string> A(N); rep(i,N) cin >> A[i];
    vector<string> ans(N, string(N, ' '));
    rep(y,N) rep(x,N) {
        int l = min({x,y,N-1-x,N-1-y});
        if      (l%4 == 0) {
            int X = N-1-y;
            int Y = x;
            ans[Y][X] = A[y][x];
            //cout << "x=" << x << " y=" << y << " X=" << X << " Y=" << Y << " : "<< A[y][x] << endl;
        }
        else if (l%4 == 1) {
            int X = N-1-x;
            int Y = N-1-y;
            ans[Y][X] = A[y][x];
            //cout << "x=" << x << " y=" << y << " X=" << X << " Y=" << Y << " : "<< A[y][x] << endl;
        }
        else if (l%4 == 2) {
            int X = y;
            int Y = N-1-x;
            ans[Y][X] = A[y][x];
            //cout << "x=" << x << " y=" << y << " X=" << X << " Y=" << Y << " : "<< A[y][x] << endl;
        }
        else if (l%4 == 3) {
            ans[y][x] = A[y][x];
            //cout << "x=" << x << " y=" << y << " : "<< A[y][x] << endl;
        }
    }
    rep(i,N) cout << ans[i] << endl;
    return 0;
}
