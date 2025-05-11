# 問題 https://atcoder.jp/contests/abs/tasks/abc085_c
# 解説 https://delta114514.hatenablog.jp/entry/2018/03/15/014555

N, Y = map(int, input().split())
Y = int(Y/1000)  # 少し速くなる

# 合計がNになる３つの数字
for a in range(N+1):  # 持っている１万円札の枚数
    for b in range(N+1-a):  # 持っている５千円札の枚数
        c = N - a - b
        if a*10 + b*5 + c == Y:
            print(a, b, c)
            exit()

print("-1 -1 -1")
