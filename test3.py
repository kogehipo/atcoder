#import bisect,collections,copy,heapq,itertools,math,numpy,string
from sys import stdin

# 1行の整数
N = int(stdin.readline())  # 整数
X, Y, Z = map(int, stdin.readline().split())  # 複数の整数
A = list(map(int, stdin.readline().split())) # リスト
A = [int(t) - 1 for t in stdin.readline().split()] # 0始まりにリスト

# 複数行の整数
A = [int(stdin.readline()) for i in range(N)]  # 整数
V = [list(map(int, stdin.readline().split())) for _ in range(N)]  # 複数/複数行の整数を2次元リスト

# 1行の文字列
S = stdin.readline().rstrip()  # 文字列
A = list(stdin.readline().rstrip())  # 文字にバラしてリスト
A = stdin.readline().rstrip().split()  # 空白区切りでリストに
A = stdin.readline().rstrip().split(',')  # カンマ区切りでリストに

# 複数行の文字列
A = [stdin.readline().rstrip() for _ in range(N)]  # 全体をリストに
A = [list(stdin.readline().rstrip()) for _ in range(N)]  # 1文字ずつバラして2次元リストに

# 文字列が複数書かれた複数行（全体を2次元リストに）
A = [list(stdin.readline().rstrip().split()) for _ in range(N)]

ans = 0

print(ans)
