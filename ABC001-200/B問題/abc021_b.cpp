#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N; cin >> N;
    int a; cin >> a;
    int b; cin >> b;
    int K; cin >> K;
    set<int> st;
    rep(i, K) {
        int x; cin >> x;
        st.insert(x);
    }
    st.insert(a);
    st.insert(b);
    if (st.size() != K+2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
