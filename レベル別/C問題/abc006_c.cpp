#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define coutf cout << fixed << setprecision(8)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

#define swap(a,b) {int tmp = a; a = b; b = tmp;}

int main()
{
    int N,M; cin >>N>>M;
    int oddOld = 0;

    // 足が奇数なら老人が一人必要
    if (M%2 == 1) {
        oddOld = 1;  // 老人を一人登録
        N-=1;  // 一人減る
        M-=3;  // 足が３本減る
        if (N < 0 || M < 0) {
            cout << "-1 -1 -1" << endl;
            return 0;
        }
    }

//cout << "N=" << N << " M=" << M << endl;
//int cnt=0;

    int adult, baby, old;
    for (old = (M/3+1)/2*2; old>=0; old-=2) {  // 老人２人（足６本）ずつ試す
        int n = N - old;
        int m = M - old*3;
        if (n < 0 || m < 0) continue;
        // 赤ちゃんの数を2分法で回す
        bool found = false;
        int l = 0, r = m/4;
        while (l <= r) {
            int c = (l+r)/2;
            int legs = old*3 + c*4 + (n-c)*2;
//cout << "adult=" << n-c << " old=" << old << " baby=" /*<< l << " "<< r << " "*/<< c << " legs=" << legs << endl;
//if (10 < cnt++) return 0; 
            if (legs < M) l = c+1;
            else if (legs > M) r = c-1;
            else {
                adult = n-c;
                baby = c;
                found = true;
                break;
            }
        }
        if (found) {
            cout << adult << " "
                 << oddOld+old << " "
                 << baby << endl;
            return 0;
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}
