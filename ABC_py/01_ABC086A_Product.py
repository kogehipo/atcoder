# 問題： https://atcoder.jp/contests/abs/tasks/abc086_a
# 解説 https://delta114514.hatenablog.jp/entry/2018/03/15/014555

a, b = map(int, input().split())
if (a * b) % 2:
    print('Odd')
else:
    print('Even')

