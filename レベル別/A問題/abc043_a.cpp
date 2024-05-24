#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N;
    cin >> N;
    //int ans = 0;
    //rep(i, N) ans += i+1;
    cout << (N+1)*N/2 << endl;
    return 0;
}
