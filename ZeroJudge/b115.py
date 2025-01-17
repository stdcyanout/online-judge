while True:
    try:
        a = int(input())
        o = input()
        b = int(input())
        if o[0] == '*':
            print(a * b)
        else:
            print(a // b)
    except:
        break