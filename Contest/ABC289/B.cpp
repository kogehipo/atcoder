#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc289/tasks/abc289_b
// 解説 レ点でつながった部分を、stackを使って反転出力すれば良い

void out_data(int a)
{
    static bool add_space = false;
    if (add_space) cout << ' ';
    add_space = true;
    cout << a;
}

void clear_stack(stack<int>& st)
{
    while (!st.empty()) {
        out_data(st.top());
        st.pop();
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    rep(m, M) cin >> a[m];

    stack<int> st;
    for (int i=1, m=0; i<=N; i++) {
        // レ点がある場合はスタックにデータ格納
        if (m < M && a[m]==i) {
            m++;
            st.push(i);
        }
        // レ点がない場合
        else {
            out_data(i);      // 該当データも出して、
            clear_stack(st);  // スタックを吐き出す
        }
    }
    // 残ったスタックがあれば吐き出す
    clear_stack(st);
    cout << endl;
    return 0;
}