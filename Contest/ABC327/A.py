

#N = 3
#S = 'abc'

N = input()
S = input()

if 0 <= S.find('ab') or 0 <= S.find('ba'):
    print('Yes')
    exit()

print('No')

