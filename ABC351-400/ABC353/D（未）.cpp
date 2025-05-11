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

int main()
{
    int N; cin >> N;
    ll sum = 0;
    vector<int> A(N);
    rep(i,N) { cin >> A[i]; sum += A[i]; }
    sum = sum % 998244353;
    cout << "sum=" << sum << endl;

    vector<int> beki(10);
    beki[0] = 1;
    range(i,1,9) beki[i] = beki[i-1] * 10;
    cout << "--\n"; rep(i,10) cout << beki[i] << endl;
    rep(i,10) beki[i] = beki[i] % 998244353;
    cout << "--\n"; rep(i,10) cout << beki[i] << endl;

    vector<int> keta(10,0);
    rep(i,N) {
        keta[to_string(A[i]).size()-1]++;
    }
    rep(i,10) cout << keta[i] << " "; cout << "\n--\n";

    ll ans = 0;
    rep(i,N-1) {
        // 前半部の値を求める
        int k = to_string(A[i]).size();
        keta[k-1]--;
        ll v = 0;
        cout << "keta: "; rep(j,10) cout << keta[j] << " "; cout << endl;
        rep(j,10) {
            v += ((ll)A[i] * (((ll)beki[j+1] * keta[j]) % 998244353)) % 998244353;
        }
        // 後半部の値を求める
        sum -= A[i];
        v += sum;
        cout << "v=" << v << endl;
        // 答えに加算
        ans = (ans + v) % 998244353;
    }

    cout << ans << endl;
    return 0;
}
