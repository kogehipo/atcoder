#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

// ここから下はオプション。問題によって選択すること。

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}

//---------------------------------------------------
// 問題 
// 解説 


int main()
{
    string T;
    cin >> T;
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> idx(N);
    vector<vector<string>> S(N, vector<string>(11));

    rep(i, N) {
        S[i][0] = "";
        cin >> A[i];
        rep(j, A[i]) {
            cin >> S[i][j+1];
        }
    }
/*
    rep(i, N) {
        cout << A[i] << ' ';
        rep(j, A[i]) {
            cout << S[i][j] << ' ';
        }
        cout << endl;
    }
*/

    int ans = INF;
    while(1){
        rep(i, N) idx(N) = 0;
        rep(i, N) {
            string str = "";
            rep(j, A[i]+1) {
                if (j < A[i]) {
                    str = str+S[i][j];
                    count++;
                }
            }
    cout << '-' << str << endl;
            if (str == T) {
                if (count < ans) ans = count;
            }
        }
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
