// C言語のソースを元にしており、C++よりも、C風の書き方になっている。

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

#define SIZE 100

int a[SIZE];

// intへのポインタを2個受け取り、その値を入れ替える
void swap(int *a, int *b){
    int x;
    x = *a;
    *a = *b;
    *b = x;
}

// intの配列を受け取り、順ソートする。配列の大きさはSIZEとする。
void sort(int a[]) {
    int flag;
    do {
        flag = 0;
        for(int i=0; i<SIZE-1; i++){
            if(a[i] > a[i+1]){
                swap(&a[i], &a[i+1]);
                flag = 1;
            }
        }
    }
    while(flag);
}

int main() {
    // 大きさSIZEの配列a[]に乱数を設定する
    printf("----- Original Data -----\n");
    for(int i=0; i<SIZE; i++){
        a[i] = rand() % SIZE;
        printf("%d\n", a[i]);
    }

    // 配列a[]を順ソートする
    sort(a);

    // ソート結果を確認する
    printf("----- Sorted Data -----\n");
    for(int i=0; i<SIZE; i++){
        printf("%d\n", a[i]);
    }
}
