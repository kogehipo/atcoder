#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7FFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/abc290/tasks/abc290_c
// 解説 この回答でもまだ冗長です。詳しくは解説動画を。
//      https://www.youtube.com/watch?v=-F6qEdL_7Tk&t=3370sjj


int main()
{
    int N, K;
    cin >> N >> K;

    // 重複を省くためいったんsetに読み込む
    set<int> st;
    rep(n, N) {
        int a;
        cin >> a;
        st.insert(a);
    }

    // setのままだと扱いにくいので改めてvectorに変換
    vector<int> A;
    for(auto s : st) A.push_back(s);
    // 終端記号としてINFをセット
    A.push_back(INF);

    rep(i, A.size()) {
        if (i == K) {  // Kを超えたら終了
            cout << K << endl;
            return 0;
        }
        if (i != A[i]) {  // iと等しくない、飛んだ数字があれば終了
            cout << i << endl;
            return 0;
        }
    }
    cout << K << endl; // ここには来ないが念のため
    return 0;
}
