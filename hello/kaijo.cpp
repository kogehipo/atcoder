// C言語のソースを元にしており、C++よりも、C風の書き方になっている。

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define N 10

// for文でNの階乗を求める
long kaijo1(long n) {
    long val=1;
    for(int i=n; 2<=i; i--){
        val = val * i;
    }
    return val;
}

// while文でNの解階乗を求める
long kaijo2(long n) {
    long val=1;
    int i=n;
    while(2<=i){
        val = val * i;
        i--;
    }
    return val;
}

// while(1)でNの階乗を求める
long kaijo3(long n) {
    long val=1;
    int i=n;
    while(1){
        if(i==1)break;
        val = val * i;
        i--;
    }
    return val;
}

// goto文でNの階乗を求める
long kaijo4(long n) {
    long val=1;
    int i=n;
LOOP:
    val = val * i;
    if(--i==1)return val;
    goto LOOP;
}

// 再帰関数でNの階乗を求める
long kaijo(long n) {
    if(n==2)return (long)2;
    return n*kaijo(n-1);
}

int main() {
    printf("for文で求めた%dの階乗は %ld\n", N, kaijo1(N));
    printf("while文で求めた%dの階乗は %ld\n", N, kaijo2(N));
    printf("while(1)で求めた%dの階乗は %ld\n", N, kaijo3(N));
    printf("goto文で求めた%dの階乗は %ld\n", N, kaijo4(N));
    printf("再帰関数で求めた%dの階乗は %ld\n", N, kaijo(N));
}
