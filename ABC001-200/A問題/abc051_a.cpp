#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (char a : s) {
        if (a == ',') cout << ' ';
        else cout << a;
    }
    cout << endl;
    return 0;
}
