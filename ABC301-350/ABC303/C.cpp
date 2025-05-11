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

#define x first
#define y second


int main()
{
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;

    set<pair<int,int>> P;

    rep(i, M) {
        pair<int,int> pos;
        cin >> pos.first;  // x座標
        cin >> pos.second; // y座標
        //cin >> pos.x;  // x座標
        //cin >> pos.y; // y座標
        P.insert(pos);
    }

    //for (auto p : P) {
    //    cout << "x=" << p.first << " y=" << p.second << endl;
    //}

    pair<int,int> now{0, 0};

    rep(i, N) {
        if      (S[i] == 'R') now.first++;
        else if (S[i] == 'L') now.first--;
        else if (S[i] == 'U') now.second++;
        else if (S[i] == 'D') now.second--;

        H--;  // 体力を１消費

        if (H < 0) {  // 体力が負ならNo
            cout << "No" << endl;
            return 0;
        }

        if (P.find(now) != P.end()) {  // アイテムがあって、
            if (H < K) {  // 体力がK未満なら
                H = K;    // Kまで回復
                P.erase(now);  // 使ったアイテムは消える
            }
        }

    }
    cout << "Yes" << endl;
    return 0;
}





