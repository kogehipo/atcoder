#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    unsigned int N, M;
    cin >> N >> M;

    vector<unsigned int> A(M, 0);
    rep(i, M) {
        int c;
        cin >> c;
        int a;
        rep(j, c) {
            cin >> a;
            A[i] |= 0x1 << (a-1);
        }
    }
    //rep(i, M) {
    //    //cout << ':' << A[i] << endl;
    //    printf("%x\n", A[i]);
    //}

    unsigned int ans = 0;
    range(i, 1, (0x1 << M) - 1) {
        unsigned b = i;
        unsigned int a = 0;
        rep(j, M) {
            if (b & 0x1) a |= A[j];
            b = b >> 1;
        }
        if (a == (0x1 << N) - 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
