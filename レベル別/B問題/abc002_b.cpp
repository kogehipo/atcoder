#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string W;
    cin >> W;

    rep(i, W.size()) {
        char a = W[i];
        switch(a) {
            case 'a':
            case 'i':
            case 'u':
            case 'e':
            case 'o':
                break;
            default:
                cout << a;
        }
    }
    cout << endl;
    return 0;
}
