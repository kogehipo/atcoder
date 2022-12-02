#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
int a[SIZE];

// 二分木のデータ構造
struct btree {
    int value;          // ノードの持つ値
    struct btree *left;    // 左のブランチ（小さい値を格納）
    struct btree *right;   // 右へのブランチ（大きい値を格納）
} btree;

struct btree *root = NULL;

void add_node(struct btree *p, int value){
    if(value <= p->value){
        if(p->left==NULL){
            p->left=malloc(sizeof(btree));
            p->left->value=value;
            p->left->left=NULL;
            p->left->right=NULL;
        }else{
            add_node(p->left,value);
        }
    }else{
        if(p->right==NULL){
            p->right=malloc(sizeof(btree));
            p->right->value=value;
            p->right->left=NULL;
            p->right->right=NULL;
        }else{
            add_node(p->right,value);
        }
    }
}

void print_node(struct btree *p){
    if(p->left){
        print_node(p->left);
    }
    printf("%d\n", p->value);
    if(p->right){
        print_node(p->right);
    }
}

void sort(int a[]) {
    
    // 最初のノードを作る
    root=malloc(sizeof(btree));
    root->value=a[0];
    root->left=NULL;
    root->right=NULL;

    // 以降の値をノードに追加する
    for(int i=1; i<SIZE; i++){
        add_node(root, a[i]);
    }
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
    print_node(root);
}
