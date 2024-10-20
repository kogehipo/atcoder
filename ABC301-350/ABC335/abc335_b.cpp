#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N;
    cin >> N;
    range(i, 0, N) {
        range(j, 0, N) {
            range(k, 0, N) {
                if (i + j + k <= N) {
                    cout << i << " " << j << " " << k << endl;
                    continue;
                }
                break;
            }
        }
    }
    return 0;
}
