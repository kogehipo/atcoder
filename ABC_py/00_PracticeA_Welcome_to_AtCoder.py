# 問題 https://atcoder.jp/contests/abs/tasks/practice_1
# 解説 https://delta114514.hatenablog.jp/entry/2018/03/15/014555

# input() - 標準入力からの入力を文字列と相手受け取る
#a = input()      # これだと後でエラーになる
a = int(input())  # 整数として受け取る
#a = int(input('Type number: '))  # inut()の引数でプロンプトを表示できる

# split()の引数には区切り文字を指定する。デフォルトはスペース、改行、タブ。
# map(function, iterable, ...) は function を結果を返しながらすべての要素に適用する
b, c = map(int, input().split())

# 合計を表示するのと、３行目のエコーバックを同時に処理している
print(a + b + c, input())

##### ここから参考 #####
'''
# ３行エコーバックする
for i in range(3):
    print(input())
'''
