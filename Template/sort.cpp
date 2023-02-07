#include <bits/stdc++.h>
using namespace std;

// BUBLE_SORT ---------------------------------

// intの配列を受け取り、順ソートする。配列の大きさはsizeとする。
void bubble_sort(int a[], int size) {
    int flag;
    do {
        flag = 0;
        for(int i=0; i<size-1; i++){
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                flag = 1;
            }
        }
    }
    while(flag);
}

// HEAP_SORT ---------------------------------

// 二分木のデータ構造
struct btree {
    int value;          // ノードの持つ値
    struct btree *left;    // 左のブランチ（小さい値を格納）
    struct btree *right;   // 右へのブランチ（大きい値を格納）
} btree;

struct btree *root = NULL;

void add_node(struct btree *p, int value){
    if (value <= p->value) {
        if (p->left==NULL) {
            p->left = (struct btree *)malloc(sizeof(btree));
            p->left->value = value;
            p->left->left  = NULL;
            p->left->right = NULL;
        } else {
            add_node(p->left, value);
        }
    } else {
        if (p->right==NULL) {
            p->right = (struct btree *)malloc(sizeof(btree));
            p->right->value = value;
            p->right->left  = NULL;
            p->right->right = NULL;
        } else {
            add_node(p->right, value);
        }
    }
}

void print_node(struct btree *p){
    if(p->left){
        print_node(p->left);
    }
    cout << p->value << ' ';
    if(p->right){
        print_node(p->right);
    }
}

void heap_sort(int a[], int size) {
    
    // 最初のノードを作る
    root = (struct btree *)malloc(sizeof(btree));
    root->value = a[0];
    root->left  = NULL;
    root->right = NULL;

    // 以降の値をノードに追加する
    for(int i=1; i<size; i++){
        add_node(root, a[i]);
    }
}


// 速度比較 ---------------------------------
#define SIZE 10000

int main() {
    int size = SIZE;
    int bs_data[SIZE];
    int hs_data[SIZE];

    // 大きさSIZEの配列a[]に乱数を設定する
    printf("----- Original Data -----\n");
    for(int i=0; i<size; i++){
        bs_data[i] = hs_data[i] = rand() % SIZE;
        cout << bs_data[i] << ' ';
    }
    cout << endl;

    int t1 = clock();

    // 配列a[]を順ソートする
    bubble_sort(bs_data, size);
    cout << "----- Result of bubble_sort() -----" << endl;
    for (int i=0; i<size; i++) cout << bs_data[i] << ' ';
    cout << endl;

    int t2 = clock();

    // 配列a[]を順ソートする
    heap_sort(hs_data, size);
    cout << "----- Result of heap_sort() -----" << endl;
    print_node(root);
    cout << endl;

    int t3 = clock();

    cout << "---" << endl;
    cout << "size = " << size << endl;
    cout << "Time of bubble_sort() = " << (t2-t1) * 1000 / CLOCKS_PER_SEC << " [ms]" << endl;
    cout << "Time of heap_sort() = " << (t3-t2) * 1000 / CLOCKS_PER_SEC <<  " [ms]" << endl;
}