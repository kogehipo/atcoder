# 問題: https://atcoder.jp/contests/abs/tasks/abc087_b
# 解説 https://delta114514.hatenablog.jp/entry/2018/03/15/014555

A = int(input())
B = int(input())
C = int(input())
X = int(input())

count = 0;
for i in range(A+1):
    for j in range(B+1):
        for k in range (C+1):
            s = i*500 + j*100 + k*50;
            if s == X:
                count += 1

print(count)
