#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,C; cin >>A>>B>>C;
    if (A == 5 && B == 5 && C == 7 ||
        A == 5 && B == 7 && C == 5 ||
        A == 7 && B == 5 && C == 5 ) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
