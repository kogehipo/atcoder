#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N,K,X,Y;
    cin >>N>>K>>X>>Y;
    if (N <= K) {
        cout << N*X << endl;
        return 0;
    }
    cout << K*X+(N-K)*Y << endl;
    return 0;
}
