// 配列またはvectorからすべての順列を探す

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "---- next_permutation()の使用例（配列）\n";
    int array[] = {1,2,3};  // 昇順ソートされていることが条件
    //int array[]={3,1,2};  // これだと最後の2通りしか出てこない
    do {
        for (int i=0; i<3; i++) {
            if (i != 0) cout << " ";
            cout << array[i];
        }
        cout << endl;
    } while (next_permutation(array, array+3));

    cout << "---- prev_permutation()の使用例（配列）\n";
    int rarray[] = {3,2,1};  // 降順ソートされていることが条件
    do {
        for (int i=0; i<3; i++) {
            if (i != 0) cout << " ";
            cout << rarray[i];
        }
        cout << endl;
    } while (prev_permutation(rarray, rarray+3));

    cout << "---- next_permutation()の使用例（vector）\n";
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    do {
        for (int i=0; i<a.size(); i++) {
            if (i != 0) cout << " ";
            cout << a[i];
        }
        cout << endl;
    } while (next_permutation(a.begin(), a.end()));

    cout << "---- prev_permutation()の使用例（vector）\n";
    vector<int> r;
    r.push_back(3);
    r.push_back(2);
    r.push_back(1);
    do {
        for (int i=0; i<r.size(); i++) {
            if (i != 0) cout << " ";
            cout << r[i];
        }
        cout << endl;
    } while (prev_permutation(r.begin(), r.end()));

}
