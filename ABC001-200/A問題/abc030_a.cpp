#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    float takahashi = (float)B/A;
    float aoki = (float)D/C;
    if (takahashi == aoki) cout << "DRAW" << endl;
    else if (takahashi > aoki) cout << "TAKAHASHI" << endl;
    else cout << "AOKI" << endl;
    return 0;
}
