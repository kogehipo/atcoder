# ・スニペット登録して呼び出す方が合理的かもしれません。要検討。
# ・1行目のimportは該当する機能を使わない場合は削除してください。
#import bisect,collections,copy,heapq,itertools,math,numpy,string
from sys import stdin

# 1行の文字列
S = list(stdin.readline().rstrip())  # 文字にバラしてリスト

for s in S[:-1]:
    print(s+' ',end='')
print(S[-1])
