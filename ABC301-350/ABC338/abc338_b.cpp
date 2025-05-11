#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    string S;
    cin >> S;
    vector<int> A(26, 0);
    int i = 0;
    while (S[i] != '\0') { A[S[i]-'a']++; i++; }
    auto max_it = max_element(A.begin(), A.end());
    int idx = distance(A.begin(), max_it);
    cout << (char)('a'+ idx) << endl;
    return 0;
}
