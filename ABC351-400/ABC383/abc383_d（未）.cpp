#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (ll)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)


// Nまでの素数を列挙する（エラトステネスのふるい）
vector<ll> allPrimes(ll N) {
 
    vector<ll> primes;
 
    // すべての数について素数かどうかのフラグを持つ配列を準備する。
    // 初期値は「すべて素数」とする。
    bool not_prime[N+1] = {};
 
    // 0,1は素数ではない。2は素数。
    not_prime[0] = true;
    not_prime[1] = true;
    not_prime[2] = false;
 
    // 以下、2以降の素数判定を行う。
 
    for(ll number=2; number<=N; number++){
        // もしその数numberが素数なら、その整数倍number*nは素数ではない
        if (!not_prime[number]) {
            ll n = 2;
            while (number * n <= N) {
                not_prime[number * n] = true;
                n++;
            }
        }
    }
 
    for(ll i=0; i<=N; i++){
        if (!not_prime[i]) primes.push_back(i);
    }
    return primes;
}
 
int main()
{
    ll N; cin >> N;
 
    vector<ll> primes;
    primes = allPrimes((ll)sqrt(N));
    //for (ll i=0; i<primes.size(); i++) cout << primes[i] << ' ';
    //cout << endl;

    ll ans = 0;
    ll NUM = primes.size();
    rep(i, NUM) range(j, i+1, NUM-1) {
        if (primes[i] * primes[i] * primes[j] * primes[j] <= N) {
            ans++;
            //cout << primes[i] << " " << primes[j] << "(" << primes[i] * primes[i] * primes[j] * primes[j] << ") ans=" << ans << endl;
        } else {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}