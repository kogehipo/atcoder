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
#define coutf cout << fixed << setprecision(8)
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))

// 要素数3以上のmin/max（C++20から）例.min({1,2,3})
//#define min std::ranges::min
//#define max std::ranges::max

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

int N, M; 
vector<int> A;
queue<vector<int>> que;

// 0なら終了、1なら桁上り
void suretu(int depth)
{
    // 底に達したら出力
    if (depth == N-1) {
        while (A[N-1] <= M) {
            que.push(A);
            A[N-1]++;
        }
        return;
    }

    while(A[depth]+(N-1-depth)*10 <= M) {
        suretu(depth+1);
        A[depth]++;
        range(i,depth+1,N-1) A[i] = A[i-1] + 10;
    }

    return;
}

int main()
{
    cin >> N >> M;
    A.resize(N);
    A[0] = 1;
    range(i,1,N-1) A[i] = A[i-1] + 10;
    suretu(0);
    cout << que.size() << endl;
    while (!que.empty()) {
        vector<int> data;
        data = que.front();
        que.pop();
        rep(i,N) cout << data[i] << " ";
        cout << endl;
    }
    return 0;
}
