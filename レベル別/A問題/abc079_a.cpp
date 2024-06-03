#include <bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    cin >>N;
    if (N.find("000") != string::npos ||
        N.find("111") != string::npos ||
        N.find("222") != string::npos ||
        N.find("333") != string::npos ||
        N.find("444") != string::npos ||
        N.find("555") != string::npos ||
        N.find("666") != string::npos ||
        N.find("777") != string::npos ||
        N.find("888") != string::npos ||
        N.find("999") != string::npos ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
