#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, Q;
    cin >> N >> Q;
    set<pair<int,int>> st;
    rep(i, Q) {
        int t, a, b;
        cin >> t >> a >> b;
        if      (t == 1) st.insert(make_pair(a, b));
        else if (t == 2) st.erase(make_pair(a, b));
        else {
            pair<int,int> ab = make_pair(a, b);
            pair<int,int> ba = make_pair(b, a);
            if (st.find(ab) != st.end() &&
                st.find(ba) != st.end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}

/*
// 誤答。G(N)のメモリ割り当てできない。
int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<set<int>> G(N);
    rep(i, Q) {
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if      (t == 1) G[a].insert(b);
        else if (t == 2) G[a].erase(b);
        else {
            if (G[a].find(b) != G[a].end() &&
                G[b].find(a) != G[b].end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
*/
