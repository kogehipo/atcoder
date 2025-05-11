#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int A,B,C,D;
    cin >>A>>B>>C>>D;
    cout << min(A,B) + min(C,D) << endl;
    return 0;
}
