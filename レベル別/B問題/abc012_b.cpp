#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N;
    cin >> N;

    int hh, mm, ss;

    hh = N / 3600;
    N %= 3600;
    mm = N / 60;
    N %= 60;
    ss = N;

    //cout << hh << ':' << mm << ':' << ss << endl;
    printf("%02d:%02d:%02d\n", hh, mm, ss);
    return 0;
}
