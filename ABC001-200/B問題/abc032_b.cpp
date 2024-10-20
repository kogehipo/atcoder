#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    string s; cin >>s;
    int k; cin >>k;
    set<string> st;
    range(i,0,s.size()-k) {
        st.insert(s.substr(i,k));
    }
    cout << st.size() << endl;
    return 0;
}
