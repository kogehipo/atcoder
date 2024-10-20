#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    vector<int> C(9);
    rep(i, 9) cin >> C[i];

    // この順番にマスの数字を知る
    vector<int> order(9);

    int cntTotal = 0;

    range(i0,    0, 8)
    range(i1, i0+1, 8)
    range(i2, i1+1, 8)
    range(i3, i2+1, 8)
    range(i4, i3+1, 8)
    range(i5, i4+1, 8)
    range(i6, i5+1, 8)
    range(i7, i6+1, 8)
    range(i8, i7+1, 8)
    {
        order = {i0, i1, i2, i3, i4, i5, i6, i7, i8};
        if (cntTotal < 10) rep(i, 9) cout << order[i] << ' ';
        cout << endl;
        cntTotal++;
/*
        vector<int> order = {i0, i1, i2, i3, i4, i5, i6, i7, i8};
        bool ok = true;
        rep(i, 9)
        {
            if (C[order[i]] != i + 1)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
*/
    }
    return 0;
}
