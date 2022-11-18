# 問題 https://atcoder.jp/contests/abs/tasks/abc088_b
# 解説 https://delta114514.hatenablog.jp/entry/2018/03/15/014555

N = int(input())

'''
# sort()を使う方法
a = list(map(int, input().split()))
a.sort(reverse=True)  # sord()は元のデータを変更する
'''

# sorted()を使う方法。sorted()はソートして新しいデータを作る。
a = sorted(map(int, input().split()), reverse=True)

'''
# 素直に交互に和を求める方法。題意を明確に判断するにはこれが良いかも。
alice = 0
bob = 0
for i in range(N):
    if i % 2:
        bob += a[i]
    else:
        alice += a[i]
print(alice - bob)
'''

# 何を計算すればよいか理解できていれば、コードはこれが良い
alice = sum(a[::2])
bob = sum(a[1::2])
print(alice - bob)
