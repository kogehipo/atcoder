// 問題 うずまき
// 解説 

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

#define DOWN  0
#define RIGHT 1
#define UP    2
#define LEFT  3

int step[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    int H, W;
    long long N;
    cin >> H >> W >> N;

    int h = 0, w = 0, direction = DOWN;
    int up_limit = 0, down_limit = H-1;
    int left_limit = 1, right_limit = W-1;
    rep (n, 1, N+1) {
        if (direction == DOWN && h == down_limit) {
            direction = RIGHT;
            down_limit--;
        }
        else if (direction == RIGHT && w == right_limit) {
            direction = UP;
            right_limit--;
        }
        else if (direction == UP && h == up_limit) {
            direction = LEFT;
            up_limit++;
        }
        else if (direction == LEFT && w == left_limit) {
            direction = DOWN;
            left_limit++;
        }
        h += step[direction][0];        
        w += step[direction][1];
        cout << direction << ' ' << h << ',' << w << endl;
    }
    cout << "Row=" << w+1 << " Line=" << h+1 << endl;

    return 0;
}
