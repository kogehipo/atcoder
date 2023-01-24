#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

// lower_boundは、ソートされた配列内で、key以上の要素の内の一番左側のイテレータを返す

int main() {

    // lower_bound() を配列で使う
    int A[] = {1, 3, 3, 5, 5, 7};  // 配列で
    rep (i, 0, 6) cout << A[i] << " ";
    cout << endl;

    int a_size = sizeof(A)/sizeof(*A); // 配列の大きさの取り方
    cout << "Size of array = " << a_size << endl;
    cout << "---" << endl;

    // A[] からkeyの位置を知る
    int keys[] = {3, 4, 7, 8};

    for (int key : keys) {
        cout << "(" << key << ")を探すと、";
        int idx = lower_bound(A, A+a_size, key) - A;  // A[]のindexが得られる
        if (idx < a_size) {
            cout << "A[" << idx << "]に(" << A[idx] << ")が見つかりました。"<< endl;
        }
        else {  // 見つからなかったら配列サイズより大きいindexが返される
            cout << "見つかりませんでした。" << endl;
        }
    }

    cout << "---" << endl;

    // lower_bound() をvectorで使う
    vector<int> V = {1, 3, 3, 5, 5, 7};  // vectorで
    rep (i, 0, 6) cout << V[i] << " ";
    cout << endl;

    int v_size = V.size();
    cout << "Size of vector = " << v_size << endl;
    cout << "---" << endl;

    // A[] からkeyの位置を知る
    int keys2[] = {3, 4, 7, 8};

    for (int key : keys2) {
        cout << "(" << key << ")を探すと、";
        auto itr = lower_bound(V.begin(), V.end(), key);  // イテレータが返される
        if (itr != V.end()) {
            cout << "(" << *itr << ")が見つかりました。"; // イテレータが指す値
            cout << "これは先頭から(" << itr - V.begin() << ")番目、";
            cout << "末尾から(" << V.end() - itr << ")番目の要素です。" << endl;
        }
        else {
            cout << "見つかりませんでした。" << endl;
        }
    }

    return 0;
}
