#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)

/*
// 類題として、Nが立方数かどうかを判定する、を解く
// https://atcoder.jp/contests/code-formula-2014-quala/tasks/code_formula_2014_qualA_a

// 解法１
int main()
{
    ll N;
    cin >> N;
    ll x = pow(N, 1.0/3.0) + 0.5;
    if ( x*x*x == N) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
*/
/*
// 解法２（二分探索）
int main()
{
	int N;
	cin >> N;
    // Nは1000000以下なので
	for (int a=1, b=100; a<=b; ) {
        // 中央値の立方を求める
		int center = (a + b) / 2;
        int cube = center*center*center;
        if (cube == N) {  // 立方数
			cout << "YES" << endl;
			return 0;
        }
        // 二分探索の範囲を狭める
		if (N < cube) b = center - 1;
		else 	      a = center + 1;
	}
	cout << "NO" << endl;
}
*/

bool is_circular(ll n) {
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

/*
int main()
{
	ll N;
	cin >> N;

    // 1以上N以下の整数で、回文数であるものを探す
    for (ll i = pow(N, (double)1/3)+1; 0 < i; i--) {
        ll cube = i*i*i;
        if (N < cube) continue;
        if (is_circular(cube)) {
            cout << cube << endl;
            return 0;
        }
    }
    return 0;
}
*/

// 解説を元に書く
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i * i <= n; i++) if (is_circular(i * i * i)) ans = i * i * i;
    cout << ans << '\n';
}