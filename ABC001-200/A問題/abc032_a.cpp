#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    for (int i=((n+(a-1))/a)*a; ; i+=a) {
        if (i%b == 0) {
            cout << i << endl; 
            return 0;
        }
    }
}
