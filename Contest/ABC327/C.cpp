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


bool check(vector<int> x)
{
    sort(x.begin(), x.end());
    for(int i=0; i<9; i++) {
//cout << x[i] << " ";
        if (x[i] != i+1) return false;
    }
//cout << endl;
    return true;
}


int main()
{
    vector<vector<int>> A(9, vector<int>(9)); 
    rep(j, 9) {
        rep(i, 9) {
            cin >> A[j][i];
        }
    }

    vector<int> B(9);

    rep(j, 9) {
        rep(i, 9) {
            B[i] = A[j][i];
        }
        if (!check(B)) {
            cout << "No" << endl;
            return 0;
        }
    }

    rep(i, 9) {
        rep(j, 9) {
            B[j] = A[j][i];
        }
        if (!check(B)) {
            cout << "No" << endl;
            return 0;
        }
    }

    rep(j, 3) {
        rep(i, 3) {
            B[0] = A[j*3][i*3];
            B[1] = A[j*3][i*3+1];
            B[2] = A[j*3][i*3+2];
            B[3] = A[j*3+1][i*3];
            B[4] = A[j*3+1][i*3+1];
            B[5] = A[j*3+1][i*3+2];
            B[6] = A[j*3+2][i*3];
            B[7] = A[j*3+2][i*3+1];
            B[8] = A[j*3+2][i*3+2];
            if (!check(B)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
