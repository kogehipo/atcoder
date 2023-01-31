#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int gcd = __gcd(A, B);     // __gcdはC++17から追加された関数
    cout << "最大公約数GCDは " << gcd << endl;
    cout << "最小公倍数LCMは " << (long long)A / gcd * B << endl;
    return 0;
}
