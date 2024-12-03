#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

vector<int> C(9);

const vector<vector<int>> line = {
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6}
};

// マス目Cをxの順番で知ったときにガッカリするかどうか
bool gakkari(vector<int> &x)
{
    vector<int> A(9,-1);
    rep(i,9) {
        rep(j,8) {
            int a,b,c;
            a = line[j][0];
            b = line[j][1];
            c = line[j][2];
            if (x[i] == a && A[a] == -1 && A[b] != -1 && A[b] == A[c] && A[a] != A[b]) return true;
            if (x[i] == b && A[b] == -1 && A[c] != -1 && A[c] == A[a] && A[b] != A[c]) return true;
            if (x[i] == c && A[c] == -1 && A[a] != -1 && A[a] == A[b] && A[c] != A[a]) return true;
        }
        A[x[i]] = C[x[i]];
    }
    return false;
}

int main()
{
    rep(i, 9) cin >> C[i];
    int yes = 0, no = 0;
    vector<int> x = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    do {
        bool g = gakkari(x);
        if (g) { yes++; /*cout << 'g';*/ }
        else   { no++;  /*cout << 'n';*/ }
    } while (next_permutation(x.begin(), x.end()));
    cout << fixed << setprecision(9) << (double)no / (yes + no) << endl;
    return 0;
}
