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
    int N,S,T; cin >>N>>S>>T;
    vector<int> A(N), B(N), C(N), D(N);
    rep(i,N) cin >>A[i]>>B[i]>>C[i]>>D[i];

    vector<int> p;
    rep(i,N) p.push_back(i);

    double time = (double)LINF;
    // N本の線分のすべての順列を試す
    do {
        // N本の各線分を順方向(A,b→C,D)と逆方向のどちらで移動するかを全探索
        for (int bit=0; bit<(0x1<<N); bit++) {
            unsigned int mask = 0x1;
            for (int n=0; n<N; n++) {
                int x = 0, y = 0;  // 初期位置
                double t = 0.0;
                rep(i,N) {
                    int sx = A[p[i]]; int sy = B[p[i]];  // 始点
                    int ex = C[p[i]]; int ey = D[p[i]];  // 終点
                    if (bit & mask) { swap(sx,ex); swap(sy,ey); }  // 逆方向なら座標交換
                    mask = mask << 1;
                    t += sqrt((sx-x)*(sx-x) + (sy-y)*(sy-y))/(double)S;  // 始点まで移動
                    t += sqrt((ex-sx)*(ex-sx) + (ey-sy)*(ey-sy))/(double)T;  // 終点までレーザー処理
                    x = ex; y = ey;
                }
                //cout << "t=" << t << endl;
                time = min(time, t);
            }
        }
    } while (next_permutation(all(p)));

    cout << fixed << setprecision(10) << time << endl;
    return 0;
}
