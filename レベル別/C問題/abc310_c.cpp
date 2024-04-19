#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) begin(a), end(a)

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    set<string> st;

    rep(i, N) {
        if (st.find(S[i]) != st.end()) {
            continue;
        }
        string r = S[i];
        reverse(all(r));
        if (st.find(r) != st.end()) {
            continue;
        } else {
            st.insert(S[i]);
        }
    }
    cout << st.size() << endl;
    return 0;
}
