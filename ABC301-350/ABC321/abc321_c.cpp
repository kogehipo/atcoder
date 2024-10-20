#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

vector<int> A = {0,1};
int keta = 1; // 最上位桁（0始まり）

void outans() {
    for (int i = keta; i >= 0; i--) cout << A[i];
    cout << endl;
    //cout << ' ';
}

void getnext() {
    // 下の桁から見ていく
    range(i, 0, keta-1) {
        // その桁だけ+1すれば済む場合
        if (A[i] < A[i+1]-1) {
            A[i]++;
            return;
        }
        A[i] = i;
    }

    // 最上位まで来た場合
    A[keta]++;
    if (A[keta] < 10) return;

    A.push_back(0);
    keta++;
    int n = 0;
    range(i, 0, keta) {
        A[i] = n;
        n++; 
    }
    return;
}

int main()
{
    int K;
    cin >> K;
    if (K <= 10) {
        cout << K << endl;
        return 0;
    }

int prev = 10;

    range(k, 1, K-10) {
        getnext();
        //cout << k << ":";
        //outans();
    }
    outans();
    return 0;
}
