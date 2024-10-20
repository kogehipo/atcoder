#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define pydiv(a,b) ((0<(a)&&0<(b)||(a)<0&&(b)<0) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
//#define pymod(a,b) ((0<(a)&&0<(b)||(a)<0&&(b)<0) ? (a)%(b) : ((a)%(b)+(b))%(b))
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))

int main()
{
    ll A, M, L, R;
    cin >> A >> M >> L >> R;
    L -= A;
    R -= A;
    cout << pydiv(R,M) - pydiv(L-1,M) << endl;
    return 0;
}
