#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;

// Pythonと同じ動きの剰余演算
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
// Pythonと同じ動きの除算
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))

template< typename T >
inline T pymod3(T a, T b) {
    return ((a ^ b) < 0) && a % b != 0 ? a % b + b : a % b;
}

template< typename T >
inline T pydiv3(T a, T b) {
    return ((a ^ b) < 0) && a % b != 0 ? a / b - 1 : a / b;
}

int main()
{
    auto a = -7;
    auto b =  6;
    //auto a = -(0x7FFFFFFFFFFFFF);
    //auto b =   0x7FFFFFFFFFFFFE;
    cout << "a=" << a << " b=" << b << endl;
    cout << pydiv3(a, b) << endl;
    cout << pymod3(a, b) << endl;

    cout << "i     :"; for (int i=-5; i<6; i++) cout << i << " "; cout << endl;
    cout << "a%b   : "; for (int i=-5; i<6; i++) cout << i%3 << " "; cout << endl;
    cout << "pymod : "; for (int i=-5; i<6; i++) cout << pymod(i, 3) << " "; cout << endl;
    cout << "pymod3: "; for (int i=-5; i<6; i++) cout << pymod3(i, 3) << " "; cout << endl;
    cout << "pydiv : "; for (int i=-5; i<6; i++) cout << pydiv(i, 3) << " "; cout << endl;
    cout << "pydiv3: "; for (int i=-5; i<6; i++) cout << pydiv3(i, 3) << " "; cout << endl;

    cout << pydiv(3, 3) << endl;
    cout << pydiv(-3, -3) << endl;

}
