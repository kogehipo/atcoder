#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))

int main()
{
    ll sx,sy,tx,ty;
    cin >>sx>>sy>>tx>>ty;

    // 同じタイル内で、左側に寄せる
    if ((sx+sy) % 2 != 0) sx--;
    if ((tx+ty) % 2 != 0) tx--;

    // (sx,sy)を2単位で移動して、原点付近に移動
    ll a;
    //a = (sx/2)*2; sx -= a; tx -= a;  // これは駄目
    //a = (sy/2)*2; sy -= a; ty -= a;
    a = pydiv(sx,2)*2; sx -= a; tx -= a;
    a = pydiv(sy,2)*2; sy -= a; ty -= a;
    //a = (sx>>1)*2; sx -= a; tx -= a;  // これでも良い
    //a = (sy>>1)*2; sy -= a; ty -= a;
    //cout << "(" << sx << "," << sy << ") (" << tx << "," << ty << ")" << endl;

    // (sx,sy)は(0,0)(1,1)のいずれか → (0,0)に移動
    if (sx == 1 && sy == 1) { sx--; sy--; tx--; ty--; }
    //cout << "(" << sx << "," << sy << ") (" << tx << "," << ty << ")" << endl;

    // (tx,ty)を第１象限に移動
    if (tx < 0) tx = -tx; 
    if (ty < 0) ty = -ty; 
    //cout << "(" << sx << "," << sy << ") (" << tx << "," << ty << ")" << endl;

    if (tx<=ty) {
        cout << ty << endl;
    } else {
        cout << ty + (tx-ty)/2 << endl;
    }
    return 0;
}
