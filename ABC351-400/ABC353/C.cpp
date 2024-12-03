#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (ll)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

ll N, idx;
vector<ll> A; 
vector<ll> S(300010); 

// indexがkeyの条件を満たすかどうか判定する評価関数
bool isOK(ll key, ll index) {
    // key以上の値を求めるので「<=」で比較している。問題に応じて変更すること。
    if ((ll)100000000 <= key + A[index]) return true;
    return false;
}
 
// 二分探索のコア部分：ある条件を満たす領域/満たさない領域の境界を探す
ll bsearch(ll key) {
    // 探索範囲を決定（ngとokの値の大小関係は不問）
    // 初期値はデータ範囲の１つ外側に設定する
    ll ng = idx; // A[0]が条件を満たすこともあるので、初期値は -1
    ll ok = N+1; // A[N-1]が条件を満たさないこともあるので、初期値はN
 
    while (abs(ok - ng) > 1) {  // ok/ngの境界が確定するまで（差が1になるまで）繰り返す
        ll mid = (ok + ng) / 2;  // 中央値
        if (isOK(key, mid)) ok = mid;  // 中央値が条件を満たす
        else                ng = mid;  // 中央値が条件を満たさない
    }
    // 境界が定まったとき、ok/ngの欲しい方の値を返す
    return ok;
    //return ng; // ngの方が欲しい場合はこちらを返す
}

int main()
{
    cin >> N;
    //A[0] = -1;  // 1始まり
    A.push_back(-1);  // 1始まり
    range(i, 1, N) {
        ll a; cin >> a;
        //A[i] = a % 100000000;
        A.push_back(a % 100000000);
    }
    sort(all(A));  // 昇順ソート

    // A[i]〜A[N]の合計を求めておく
    S[0] = -1;  // 1始まり
    S[N] = A[N];
    for (ll i=N-1; 1<=i; i--) {
        S[i] = S[i+1] + A[i];
    }
    //cout << "累積和："; rep(i, N+1) cout << S[i] << " "; cout << endl;

    ll ans = 0;
    ll carry;
    //range(i, 1, N-1) {
    for (idx=1; idx<=N-1; idx++) {
        //cout << "idx=" << idx << endl;
/*
        carry = N+1;  // 100000000を超えたときのindex
        range(j, idx+1, N) {
            if (100000000 <= A[idx] + A[j]) {
                carry = j;
                break;
            }
        }
*/
        // 高速化のために二分探索を使う
        carry = bsearch(A[idx]);
        //cout << A[idx] << " ";
        //cout << "carry=" << carry << endl;

        ans += A[idx] * (N-idx) + S[idx+1];
        //cout << "ans=" << ans << endl;
        if (carry != N+1) {
            ans -= (N - carry + 1) * (ll)100000000;
        }
    }

    cout << ans << endl;
    return 0;
}
