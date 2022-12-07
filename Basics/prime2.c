// 素数を求める（２）

#include <stdio.h>

#define LIMIT 100000

#define YES 1  // 素数である
#define NO  0  // 素数ではない

int main() {

    // すべての数について素数かどうかのフラグを持つ配列を準備する。
    // 初期値は「すべて素数」とする。
    int primes[LIMIT+1];
    for (int i=0; i<=LIMIT; i++) primes[i] = YES;

    // 0,1は素数ではない。2は素数。
    primes[0] = NO;
    primes[1] = NO;
    primes[2] = YES;

    // 以下、2以降の素数判定を行う。

    for(int number=2; number<=LIMIT; number++){
        // もしその数numberが素数なら、その整数倍number*nは素数ではない
        if(primes[number] == YES){
            int n = 2;
            while (number * n <= LIMIT) {
                primes[number * n] = NO;
                n++;
            }
        }
    }

    for(int i=0; i<=LIMIT; i++){
        if (primes[i] == YES) printf("%d\n", i);
    }
}
