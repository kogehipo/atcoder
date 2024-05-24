#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int xGroup, yGroup;
    switch (x)
    {
    case 2:
        xGroup = 1;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        xGroup = 2;
        break;
    default:
        xGroup = 3;
        break;
    }
    switch (y)
    {
    case 2:
        yGroup = 1;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        yGroup = 2;
        break;
    default:
        yGroup = 3;
        break;
    }
    if (xGroup == yGroup) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
