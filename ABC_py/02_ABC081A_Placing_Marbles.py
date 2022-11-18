# 問題: https://atcoder.jp/contests/abs/tasks/abc081_a
# 解説 https://delta114514.hatenablog.jp/entry/2018/03/15/014555

print(input().count('1'))

# 素直にCから変換するとこうなる
'''
s = list(input())
count = 0
for i in range(3):
    if s[i] == '1':
        count += 1
print(count)
'''
