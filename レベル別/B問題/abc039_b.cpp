#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)

int root(int x) {
    return (int)sqrt(x);
}

int main()
{
    int X; cin >>X;
    cout << root(root(X)) << endl;
    return 0;
}
