B = int(input())

for A in range(1,100):
    V = 1
    for i in range(0, A):
        V *= A;
        if B < V:
            print('-1')
            exit()
        elif B == V:
            print(A)
            exit()
