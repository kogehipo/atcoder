# ・スニペット登録して呼び出す方が合理的かもしれません。要検討。
# ・1行目のimportは該当する機能を使わない場合は削除してください。
#import bisect,collections,copy,heapq,itertools,math,numpy,string
from sys import stdin
 
N = int(stdin.readline())
A = list(map(int, input().split()))
B = set(A)
C = list(B)
C.sort()
print(C[-2])
