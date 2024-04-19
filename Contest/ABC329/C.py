from sys import stdin

N = int(stdin.readline())  # 整数
#S = stdin.readline().rstrip()  # 文字列
S = stdin.readline()  # 改行コード（ありえない文字）を終端の目印として使うため、あえて残す
len = len(S) # lenは改行コードを含む
foundlist = set([])  # 見つかった部分文字列の集合（重複なし）その要素は(文字,文字数)のタプル

l = 0  # 部分文字列の左端
while True:
    for r in range(l+1, len):  # 部分文字列の右端
        # ここで、文字はＳ[l]、文字数はr-l
        foundlist.add((S[l], r-l))  # 見つかった部分文字列を集合に追加
        if S[l] != S[r]: break  # 異なる文字or終端でbreakする
    l = r  # 次の部分文字列の左端
    if l == len-1: break  # 文字列の終端なら終了

#print(foundlist)  # 結果の確認
#print(len(foundlist))  # なぜかエラーになるのでループで数える
ans = 0
for ch, n in foundlist:
    ans += 1
print(ans)
