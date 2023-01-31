#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//#define USE_STD_FUNC
//#define BUBLE_SORT
#define HEAP_SORT

#ifdef USE_STD_FUNC
int main() {

    // 配列で
    int A[] = {5, 4, 7, 2, 8, 7, 3};  // 配列で
    int size = sizeof(A)/sizeof(A[0]);
    rep (i, size) cout << A[i] << " ";
    cout << endl;

    sort(A, A+size);
    rep (i, size) cout << A[i] << " ";
    cout << endl;

    sort(A, A+size, greater<>());
    rep (i, size) cout << A[i] << " ";
    cout << endl;

    cout << "---" << endl;

    // vectorで
    vector<int> V = {5, 4, 7, 2, 8, 7, 3};  // vectorで
    rep (i, V.size()) cout << V[i] << " ";
    cout << endl;

    sort(V.begin(), V.end());
    rep (i, V.size()) cout << V[i] << " ";
    cout << endl;

    sort(V.begin(), V.end(), greater<>());
    rep (i, V.size()) cout << V[i] << " ";
    cout << endl;

    return 0;
}
#endif

#ifdef BUBLE_SORT
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
#endif


#ifdef HEAP_SORT

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
    printf("%d\n", p->value);
    if(p->right){
        print_node(p->right);
    }
}

void sort(int a[]) {
    
    // 最初のノードを作る
    root = (struct btree *)malloc(sizeof(btree));
    root->value = a[0];
    root->left  = NULL;
    root->right = NULL;

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

#endif
