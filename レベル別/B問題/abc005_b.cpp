#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;
    vector<int> T(N);
    rep(i, N) cin >> T[i];
    auto it = min_element(T.begin(), T.end());
    cout << *it << endl;
    return 0;
}
