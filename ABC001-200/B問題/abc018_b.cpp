#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S;
    cin >> S;
    int N;
    cin >> N;
    rep(n, N) {
        int l;  cin >> l;
        int r;  cin >> r;
        for (; l < r; l++, r--) {
            swap(S[l-1], S[r-1]);
        }
    }
    cout << S << endl;
    return 0;
}
