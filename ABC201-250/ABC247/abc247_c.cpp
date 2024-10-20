#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)

vector<int> f(int N) {
    if (N == 0) {
        return {};
    }
    else if (N == 1) {
        return {1};
    }
    else {
        vector<int> v = {N};
        vector<int> t = f(N-1);
        v.insert(v.begin(), all(t));
        v.insert(v.end(), all(t));
        return v;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> ans = f(N);
    rep(i, ans.size()) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
