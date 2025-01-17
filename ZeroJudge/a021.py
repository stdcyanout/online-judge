a, b, c = input().split()
a = int(a)
c = int(c)
if b == '+':
    print(a + c)
elif b == '-':
    print(a - c)
elif b == '*':
    print(a * c)
elif b == '/':
    print(a // c)