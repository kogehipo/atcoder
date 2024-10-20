#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    string S;
    cin >>S;
    vector<string> A = {"abc","acb","bac","bca","cab","cba"};
    if (find(all(A),S)!=A.end()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
