#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------
// 問題 
// 解説 


// xの素数判定を行う
bool isPrime(int x)
{
    if (x <= 1) return false;
    for (int i=2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}


// Nまでの素数を列挙する
vector<int> allPrimes(int N) {

    vector<int> primes;

    // すべての数について素数かどうかのフラグを持つ配列を準備する。
    // 初期値は「すべて素数」とする。
    bool not_prime[N+1] = {};

    // 0,1は素数ではない。2は素数。
    not_prime[0] = true;
    not_prime[1] = true;
    not_prime[2] = false;

    // 以下、2以降の素数判定を行う。

    for(int number=2; number<=N; number++){
        // もしその数numberが素数なら、その整数倍number*nは素数ではない
        if (!not_prime[number]) {
            int n = 2;
            while (number * n <= N) {
                not_prime[number * n] = true;
                n++;
            }
        }
    }

    for(int i=0; i<=N; i++){
        if (!not_prime[i]) primes.push_back(i);
    }
    return primes;
}


// Nまでの素数を列挙する
vector<int> allPrimes2(int N)
{
    vector<int> primes; // 素数を記録する配列。サイズはNの半分にしておく
    int n;             // 見つけた素数の数-1
    int number;        // 素数かどうか調べる数

    // 最初の素数は2
    primes.push_back(2);

    // 3からLIMITまで繰り返す。
    // ただし偶数は素数ではないので2ずつインクリメントする。
    for(int number=3; number<=N; number+=2){
        int flag = 0;
        for(int i=0; i<=primes.size(); i++){
            // 割り切れたら素数ではない
            if (!(number%primes[i])) {
                flag = 1;
                break;
            }
        }
        if (flag) continue; // 素数ではない
        primes.push_back(number);
    }
    return primes;
}


int main()
{
    // 素数判定
    int N;
    N = -1; cout << N << " は " << (isPrime(N) ? "素数" : "素数ではない") << endl;
    N = 0; cout << N << " は " << (isPrime(N) ? "素数" : "素数ではない") << endl;
    N = 1; cout << N << " は " << (isPrime(N) ? "素数" : "素数ではない") << endl;
    N = 5; cout << N << " は " << (isPrime(N) ? "素数" : "素数ではない") << endl;
    N = 7; cout << N << " は " << (isPrime(N) ? "素数" : "素数ではない") << endl;
    N = 9; cout << N << " は " << (isPrime(N) ? "素数" : "素数ではない") << endl;
    N = 10; cout << N << " は " << (isPrime(N) ? "素数" : "素数ではない") << endl;

    // 素数列挙(1)
    vector<int> primes;
    primes = allPrimes(103);
    for (int i=0; i<primes.size(); i++) cout << primes[i] << ' ';
    cout << endl;

    // 素数列挙(2)
    primes = {};
    primes = allPrimes2(103);
    for (int i=0; i<primes.size(); i++) cout << primes[i] << ' ';
    cout << endl;

    return 0;
}
