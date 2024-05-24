#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int A,B,C,D;
    cin >>A>>B>>C>>D;
    ll AB = A*B;
    ll CD = C*D;
    cout << max(AB,CD) << endl;
    return 0;
}
