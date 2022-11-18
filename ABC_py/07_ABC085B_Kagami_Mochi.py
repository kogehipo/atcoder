# 問題 https://atcoder.jp/contests/abs/tasks/abc085_b
# 解説 https://delta114514.hatenablog.jp/entry/2018/03/15/014555

'''
N = int(input())

#d = {}  # これではうまくいかない
d = set()  # 空集合を準備
for n in range(N):
    d.add(int(input()))  # 既に同じ要素があれば何も起きない

print(len(d))
'''

# 模範解答。ただし可読性は劣悪。
N = int(input())
print(len(set(map(int, [input() for i in range(N)]))))
