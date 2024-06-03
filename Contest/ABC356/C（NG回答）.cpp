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

// 座標をsetで扱えるようにする。pairのメンバー名first,secondが嫌なので。
struct Point { int x, y; };
bool operator<(const Point &p1, const Point &p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    else              return p1.y < p2.y;
}
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

vector<vector<long long>> pascal_triangle(int N) {
 
    // N+1*N+1の2次元vectorを0で初期化しておく
    // ここにパスカルの三角形を作る
    vector<vector<long long>> v(N+1, vector<long long>(N+1, 0));
 
    for (int i=0; i<=N; i++) {
        v[i][0] = 1;  // N個から0個を選ぶのは1通り
        v[i][i] = 1;  // N個からN個を選ぶのは1通り
    }
 
    // パスカルの三角形を埋めていく
    for (int n=1; n<=N; n++) {  // 母集合の大きさ：1からNまで繰り返す
        for (int k=1; k<n; k++) {  // 各集合で、1からその大きさn-1まで繰り返す
            v[n][k] =           // n個からk個を選ぶ組合せは、
                v[n-1][k-1] +   // 自分を選んだ場合、n-1からk-1を選ぶ組合せと、
                v[n-1][k];      // 自分を選ばなかった場合、n-1からkを選ぶ組合せ、の和
        }
    }
/*
    // 確認のためパスカルの三角形を表示
    for (int n=0; n<=N; n++) {
        for (int k=0; k<=N; k++) {
            cout << v[n][k] << ' ';
        }
        cout << ": " << n << "個からK個を選ぶ組合せの数" << endl;
    }
*/
    return v;
}
 
int combination(int N, int K)
{
    return pascal_triangle(N)[N][K];
}

int main()
{
    int N,M,K;
    cin >>N>>M>>K;
    vector<int> C(M);
    vector<vector<bool>> Used(M, vector<bool>(N, false));
    vector<char> R(M);
    rep(i, M) {
        cin >> C[i];
        rep(j, C[i]) {
            int num;
            cin >> num;
            Used[i][num-1] = true;
        }
        cin >> R[i];
    }

#define UNKNOWN 0
#define CORRECT 1
#define DUMMY 2
    vector<int> Judge(N, UNKNOWN);

    rep(i, M) {
        if (R[i] == 'o') {  // 開いたとき
            rep(j, N) {
                if (!Used[i][j]) {  // 使っていないのは
                    if (Judge[j] == CORRECT) {  // 矛盾する
                        cout << 0 << endl;
                        return 0;
                    }
                    Judge[j] = DUMMY;  // ダミーである
                    //cout << "DUMMY found : " << j << endl;
                }
                if (C[i] == K && Used[i][j]) {
                    if (Judge[j] == DUMMY) {  // 矛盾する
                        cout << 0 << endl;
                        return 0;
                    }
                    Judge[j] = CORRECT;  // 使っているのは本物である
                }
            }
        }
        else if (R[i] == 'x') {  // 開かなかったとき
            int cnt = -1;
            rep(j, N) {
                if (!Used[i][j]) {  // 使っていないキーを探して
                    if (cnt == -1) cnt = j;
                    else { cnt = -1; break; }
                }
                if (cnt != -1) {
                    if (Judge[cnt] == DUMMY) { // 矛盾する
                        cout << 0 << endl;
                        return 0;
                    }
                    Judge[cnt] = CORRECT;  // １本だけならそれは本物
                }
            }
        }
    }

    int numCorrect = 0;
    int numDummy = 0;
    rep (i, N) {
        if (Judge[i] == CORRECT) numCorrect++;
        if (Judge[i] == DUMMY) numDummy++;
    }

    cout << "--" << endl;
    cout << "correct=" << numCorrect << " dummy=" << numDummy << endl;

    // 必要な本物の数
    K -= numCorrect;
    // 未確定なキーの数
    int numUnknown = N - numCorrect - numDummy;
    cout << "numUnknown=" << numUnknown << " K=" << K << endl;

    if (K == numUnknown) {
        cout << 1 << endl;
        return 0;
    } else if (K < 0 || numUnknown < K) {
        cout << 0 << endl;
        return 0;
    }

    // numUnknown から K 個選ぶ
    //ll ans = 1;
    //for (int i=0; i<K; i++) ans *= numUnknown - i;  // 桁が溢れる
    //for (int i=0; i<K; i++) ans /= i+1;
    //cout << ans << endl;
    cout << combination(numUnknown, K) << endl;
    return 0;
}
