from sys import stdin
N = int(stdin.readline())
D = list(map(int, input().split()))
ans = 0
for m in range(1, N+1):
    for d in range(1, D[m-1]+1):
        X = str(m) + str(d)
        #print(X)
        zorome = True
        z = '0'
        for x in X:
            if z == '0':
                z = x
            elif z != x:
                zorome = False
                break
        if zorome:
            ans += 1
print(ans)

            