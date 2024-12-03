#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7FFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N; cin >>N;
    vector<int> A(N); rep(i,N) cin >>A[i];
    vector<int> B(N/2);
    int ans = 0;
    // 0始まりと1始まりの2通りで試す
    for (int odd_even=0; odd_even<=1; odd_even++) {
        // A[]を2文字ずつ纏めてB[]に変換する
        int b = 0;
        for (int a=odd_even; a<N; a+=2) {
            if (N-1 <= a) continue;
            if (A[a] == A[a+1]) B[b] = A[a];
            else B[b] = -1;
            b++;
        }
        //cout << "B: "; rep(i,b) cout << B[i] << " "; cout << endl;
        // Bに対して、異なる値が連続する部分列の最大長を求める
        map<int,int> mp; // 各値が出現した場所を記録する
        int cnt = 0; // 数列の長さ（の1/2）
        int left = -1;  // 数列の左端インデックス
        rep(i,b) {
            if (B[i] == -1) {  // 不連続が出現。最初からやり直し。
                ans = max(ans, cnt);
                mp.clear();
                cnt = 0;
                left = -1;
            } else if (mp.find(B[i]) != mp.end()
                        && left <= mp[B[i]]) {  // 現在の数列の中に既出データが現れた
                ans = max(ans, cnt);
                left = mp[B[i]] + 1; // 数列を、既出データの次からに再定義
                mp[B[i]] = i;
                cnt = i - left + 1;
            } else {  // 新しいデータ、または既出データが現れたがleftより前
                if (left == -1) left = i;  // 新しいデータ列開始
                mp[B[i]] = i;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans*2 << endl;
    return 0;
}
