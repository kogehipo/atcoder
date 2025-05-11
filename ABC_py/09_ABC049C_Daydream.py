# 問題 https://atcoder.jp/contests/abs/tasks/arc065_a
# 解説 https://delta114514.hatenablog.jp/entry/2018/03/15/014555

# dream    maerd
# dreamer  remaerd
# erase    esare
# eraser   resare

'''
# 模範解答
s = input()

while s:
    for query in ("erase", "eraser", "dream", "dreamer"):
        if s.endswith(query):
            s = s[:-len(query)]
            break
    else:  # breakされなかったとき、つまり、合致する文字列がなかった場合
        print('NO')
        exit()

print('YES')
'''

# あえて前から処理してみる
s = input()

i = 0
while i < len(s):
    if s[i:].startswith("dreamera"):
        i += 5
    elif s[i:].startswith("dreamer"):
        i += 7
    elif s[i:].startswith("dream"):
        i += 5
    elif s[i:].startswith("eraser"):
        i += 6
    elif s[i:].startswith("erase"):
        i += 5
    else:
        print('NO')
        exit()

print('YES')
