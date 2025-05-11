# 問題 https://atcoder.jp/contests/abs/tasks/abc081_b
# 解説 https://delta114514.hatenablog.jp/entry/2018/03/15/014555

'''
# 普通にループさせた場合
# 1行目を読む
N = int(input())

# 2行目を読む
#A = map(int, input().split())   # これは間違い
A = list(map(int, input().split()))

count = 0
odd_found = False
while True:
    for n in range(N):
        if (A[n] % 2) == 1:
            odd_found = True
            break
        else:
            A[n] /= 2

    if odd_found:
        print(count)
        exit()

    count += 1
'''


'''
# 下で使っているテクニックの確認
print('000110100')
print(type('000110100'))
print('000110100'.index('1'))
print(reversed('000110100'))
#print(reversed('000110100').index('1'))  # これはエラーになる
print(list(reversed('000110100')))
print(type(reversed('000110100')))
print(list(reversed('000110100')).index('1'))
exit()
'''

# 解説のコード
n = input()
a = list(map(int, input().split()))

ans = float("inf")   # 初期値を無限大に設定
for v in a:
    # 2進数で下桁に連続する0を数える（逆順にして先頭から数えている）
    ans = min(ans, list(reversed(bin(v))).index('1'))
    
print(ans)
