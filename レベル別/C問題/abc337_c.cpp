#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(n, N) cin >> A[n];

    map<int, int> mp;
    rep(n, N) mp[A[n]] = n+1;

    int mae;
    mae = mp[-1];
    cout << mae;
    range(i, 2, N) {
        cout << ' ' << mp[mae];
        mae = mp[mae];
    }
    cout << endl;
    return 0;
}
