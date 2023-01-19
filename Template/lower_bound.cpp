#include <bits/stdc++.h>
using namespace std;

// lower_boundは、ソートされた配列内で、key以上の要素の内の一番左側のイテレータを返す

int main() {


    // 配列で試す
    int a[]       = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};  // 配列で
    int a_size = sizeof(a)/sizeof(*a); // 配列の大きさの取り方
    cout << "Size of array = " << a_size << endl;

    //イテレータを返す
    auto ai1 = lower_bound(a, a+a_size, 4);
    auto ai2 = lower_bound(a, a+a_size, 6);
    auto ai3 = lower_bound(a, a+a_size, 7);
    auto ai4 = lower_bound(a, a+a_size, 19);
    auto ai5 = lower_bound(a, a+a_size, 20);

    //イテレータを返す
    int ap1 = lower_bound(a, a+a_size, 4)  - a;
    int ap2 = lower_bound(a, a+a_size, 6)  - a;
    int ap3 = lower_bound(a, a+a_size, 7)  - a;
    int ap4 = lower_bound(a, a+a_size, 19) - a;
    int ap5 = lower_bound(a, a+a_size, 20) - a;

    //値の表示
    cout << "----------value----------" << endl;
    cout << "aIter1 = " << *ai1 << " ap1=" << ap1 << endl; //Iter1 = 4
    cout << "aIter2 = " << *ai2 << " ap2=" << ap2 << endl; //Iter2 = 7
    cout << "aIter3 = " << *ai3 << " ap3=" << ap3 << endl; //Iter3 = 7
    cout << "aIter4 = " << *ai4 << " ap4=" << ap4 << endl; //Iter4 = 19
    cout << "aIter5 = " << *ai5 << " ap5=" << ap5 << endl; //Iter5 = 1326115891



    vector<int> v = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};  // vectorで
    int v_size = v.size();
    cout << "Size of vector = " << v_size << endl;

    //イテレータを返す
    auto Iter1 = lower_bound(v.begin(), v.end(), 4);
    auto Iter2 = lower_bound(v.begin(), v.end(), 6);
    auto Iter3 = lower_bound(v.begin(), v.end(), 7);
    auto Iter4 = lower_bound(v.begin(), v.end(), 19);
    auto Iter5 = lower_bound(v.begin(), v.end(), 20);

    //値の表示
    cout << "----------value----------" << endl;
    cout << "Iter1 = " << *Iter1 << endl; //Iter1 = 4
    cout << "Iter2 = " << *Iter2 << endl; //Iter2 = 7
    cout << "Iter3 = " << *Iter3 << endl; //Iter3 = 7
    cout << "Iter4 = " << *Iter4 << endl; //Iter4 = 19
    cout << "Iter5 = " << *Iter5 << endl; //Iter5 = 1326115891

    //先頭からの距離
    cout << "----------from----------" << endl;
    cout << "Iter1 = " << Iter1 - v.begin() << endl; //Iter1 = 1
    cout << "Iter2 = " << Iter2 - v.begin() << endl; //Iter2 = 3
    cout << "Iter3 = " << Iter3 - v.begin() << endl; //Iter3 = 3
    cout << "Iter4 = " << Iter4 - v.begin() << endl; //Iter4 = 9
    cout << "Iter5 = " << Iter5 - v.begin() << endl; //Iter5 = 10

    //末尾までの距離
    cout << "----------to----------" << endl;
    cout << "Iter1 = " << v.end() - Iter1 << endl; //Iter1 = 9 
    cout << "Iter2 = " << v.end() - Iter2 << endl; //Iter2 = 7
    cout << "Iter3 = " << v.end() - Iter3 << endl; //Iter3 = 7
    cout << "Iter4 = " << v.end() - Iter4 << endl; //Iter4 = 1
    cout << "Iter5 = " << v.end() - Iter5 << endl; //Iter5 = 0

    return 0;
}
