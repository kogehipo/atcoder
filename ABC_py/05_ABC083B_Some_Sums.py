# 問題 https://atcoder.jp/contests/abs/tasks/abc083_b
# 解説 https://delta114514.hatenablog.jp/entry/2018/03/15/014555

N, A, B = map(int, input().split())
total = 0
for n in range(N+1):
    # 文字列にしてバラして数値として合計すれば良い
    if A <= sum(map(int, str(n))) <= B:
        total += n
print(total)

'''
N, A, B = map(int, input().split())
total = 0
for n in range(1, N+1):
    sum = int(n/10000) + int((n%10000)/1000) + int((n%1000)/100) + int((n%100)/10) + int(n%10)
    if A <= sum <= B:
        total += n
print(total)
'''