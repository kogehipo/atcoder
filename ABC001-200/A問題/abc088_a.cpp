#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,A;
    cin >>N>>A;
    N = N%500;
    if (N <= A) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
