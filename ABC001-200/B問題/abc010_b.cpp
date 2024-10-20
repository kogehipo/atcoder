#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
/*
x       OK
xx      NG
xxx     OK
xxxx    NG
xxxxx   NG
xxxxxx  NG
*/
    int ans = 0;
    rep(i, N) {
        int a = A[i];
        a %= 6;
        switch (a) {
            case 1:
            case 3:
                break;
            case 2:
                ans += 1;
                break;
            case 4:
                ans += 1;
                break;
            case 5:
                ans += 2;
                break;
            default:
                ans += 3;
                break;
        }
    }

    cout << ans << endl;
    return 0;
}
