#a = -1100000000
#b =  1099999999
#a = 0xFFFFFFFFFFFFFFF0
#b = 0x7FFFFFFFFFFFFFF0
a =  0xFFFFFFFFFFFFFFFF
b =  0x0000000000000002
print(a//b)  # -2
print(a%b)   # 1099999998

print([i for i in range(-5, 6)])
print([i//3 for i in range(-5, 6)])
print([i%3 for i in range(-5, 6)])
