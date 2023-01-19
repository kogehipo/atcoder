// 素数を求める（１）

#include <stdio.h>

#define LIMIT 100

int main() {

    // 素数を記録する配列
    // サイズはLIMITの半分にしておく
    int primes[LIMIT/2];

    // 見つけた素数の数-1
    int n;

    // 素数かどうか調べる数
    int number;

    // 2は唯一の偶数の素数
    n = 0;
    primes[n] = 2;

    // 3からLIMITまで繰り返す。
    // ただし偶数は素数ではないので2ずつインクリメントする。
    for(int number=3; number<=LIMIT; number+=2){
        int flag=0;
        for(int i=0; i<=n; i++){
            // 割り切れたら素数ではない
            if(!(number%primes[i])){
                flag=1;
                break;
            }
        }
        if(flag){
            // 素数ではない
            continue;
        } else {
            // 素数である
            printf("前：primes[n]=%d n=%d\n",primes[n],n);
            primes[++n] = number;
            printf("後：primes[n]=%d n=%d\n",primes[n],n);
        }
    }

    for(int i=0; i<=n; i++){
        printf("%d\n", primes[i]);
    }
}
