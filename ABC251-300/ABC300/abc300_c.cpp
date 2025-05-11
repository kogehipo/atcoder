#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))


vector<string> C(110);

// おおきさsizeのバツであることは確認済み
int checkBatsu(int size, int h, int w)
{
    if (
        C[h-size][w-size] == '.' && C[h-size][w+size] == '.' &&
        C[h+size][w-size] == '.' && C[h+size][w+size] == '.' ) {

        if (C[h-size+1][w-size] != '.' || C[h-size][w-size+1] != '.' ||
            C[h-size+1][w+size] != '.' || C[h-size][w+size-1] != '.' ||
            C[h+size-1][w-size] != '.' || C[h+size][w-size+1] != '.' ||
            C[h+size-1][w+size] != '.' || C[h+size][w+size-1] != '.' ) {
            return 0;  // バツじゃない
        } else {
            return 2;  // バツ完成
        }
    } else if (
        C[h-size][w-size] == '#' && C[h-size][w+size] == '#' &&
        C[h+size][w-size] == '#' && C[h+size][w+size] == '#' ) {
            return 1; // バツ（もっと大きいかも）
    } else {
        return 0;  // バツじゃない
    }
}

int main()
{
    int H, W, N;
    cin >> H >> W;
    N = min(H, W);


    C[0] = string(W+2, '.');
    C[H+1] = string(W+2, '.');
    range(i, 1, H) {
        string s;
        cin >> s;
        C[i] = '.' + s + '.';
    }

    vector<int> ans(N, 0);
    range(h, 2, H-1) range(w, 2, W-1) {
        if (C[h ][w] != '#') continue;
        int size = 0;
        bool found = true;
        while (1) {
            // もう一つ大きいバツか？
            int ret = checkBatsu(size+1, h, w);
            if (ret == 0) {  // バツじゃない
                found = false;
                break;
            } else if (ret == 1) {  // バツ（もっと大きいかも）
                size++;
                continue;
            } else if (ret == 2) {  // バツ（完成形）
                break;
            }
        }
        if (found) ans[size-1]++;
    }

    rep(i, N) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
