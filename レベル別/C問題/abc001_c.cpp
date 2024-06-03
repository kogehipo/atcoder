#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    int deg, Dis;
    cin >> deg >> Dis;

    double Deg = (double)deg / 10.0;
    string Dir;
    if (348.75 <= Deg || Deg < 11.25) Dir = "N";
    else if (Deg < 33.75) Dir = "NNE";
    else if (Deg < 56.25) Dir = "NE";
    else if (Deg < 78.75) Dir = "ENE";
    else if (Deg < 101.25) Dir = "E";
    else if (Deg < 123.75) Dir = "ESE";
    else if (Deg < 146.25) Dir = "SE";
    else if (Deg < 168.75) Dir = "SSE";
    else if (Deg < 191.25) Dir = "S";
    else if (Deg < 213.75) Dir = "SSW";
    else if (Deg < 236.25) Dir = "SW";
    else if (Deg < 258.75) Dir = "WSW";
    else if (Deg < 281.25) Dir = "W";
    else if (Deg < 303.75) Dir = "WNW";
    else if (Deg < 326.25) Dir = "NW";
    else                   Dir = "NNW";

    int W;
    double d = (int)((double)Dis*10 /60.0 +0.5) /(double)10.0;
    if (d <= 0.2) {
        cout << "C 0" << endl;
        return 0;
    }
    else if (d <= 1.5) W = 1;
    else if (d <= 3.3) W = 2;
    else if (d <= 5.4) W = 3;
    else if (d <= 7.9) W = 4;
    else if (d <= 10.7) W = 5;
    else if (d <= 13.8) W = 6;
    else if (d <= 17.1) W = 7;
    else if (d <= 20.7) W = 8;
    else if (d <= 24.4) W = 9;
    else if (d <= 28.4) W = 10;
    else if (d <= 32.6) W = 11;
    else               W = 12;


    cout << Dir << " " << W << endl;
    return 0;
}
