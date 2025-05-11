# 問題 https://atcoder.jp/contests/abs/tasks/arc089_a
# 解説 https://delta114514.hatenablog.jp/entry/2018/03/15/014555

N = int(input())

current_t = 0;
current_x = 0;
current_y = 0;

for i in range(N):
    next_t, next_x, next_y = map(int, input().split())

    # 現在地との差分を求める
    t  = next_t - current_t;
    x  = abs(next_x - current_x)  # 絶対値を取らないとWAとなる
    y  = abs(next_y - current_y)

    if t < x+y  or  \
        ((x+y)-t) % 2:
        # 離れすぎていたらNo
        # 到達した後、残りが奇数なら到達できない
        print("No")
        exit()

    current_t = next_t;
    current_x = next_x;
    current_y = next_y;

print("Yes")
