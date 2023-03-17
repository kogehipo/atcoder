#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

//---------------------------------------------------
// 問題 https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ao
// 解説 反転操作を避ければ早くなることは明白

#if 0
// これはTLE
int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N+1);
    range(i, 1, N) A[i] = i;

    rep(j, Q) {
        int c, x, y;
        cin >> c;
        if (c==1) {
            cin >> x >> y;
            A[x] = y;
        }
        else if (c==2) {
            reverse(A.begin()+1, A.end());
        }
        else if (c==3) {
            cin >> x;
            cout << A[x] << endl;
        }
    }

    return 0;
}
#endif

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N+1);
    range(i, 1, N) A[i] = i;

    vector<int> C(Q), X(Q), Y(Q);
    rep(j, Q) {
        cin >> C[j];
        if (C[j]==1) cin >> X[j] >> Y[j];
        else if (C[j]==3) cin >> X[j];
    }

    bool ascending = true;  // 昇順（実際に反転を行わず、フラグで状態を持つ）
    rep(j, Q) {
        if (C[j]==1) {
            if (ascending) A[X[j]] = Y[j];
            else           A[N-X[j]+1] = Y[j];
        }
        else if (C[j]==2) {
            ascending = !ascending;
        }
        else if (C[j]==3) {
            if (ascending) cout << A[X[j]] << endl;
            else           cout << A[N-X[j]+1] << endl;
        }
    }

    return 0;
}
