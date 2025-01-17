import sys
import math

def main():
    option, a, b, c = sys.stdin.readline().strip().split(',')
    option = int(option)
    empty = 0
    if a == "":
        empty = 1
    else:
        a = int(a)
    if b == "":
        empty = 2
    else:
        b = int(b)
    if c == "":
        empty = 3
    else:
        c = int(c)
    if option == 1 and empty == 1:
        print(int(math.sqrt(c * c - b * b) + sys.float_info.epsilon))
    if option == 1 and empty == 2:
        print(int(math.sqrt(c * c - a * a) + sys.float_info.epsilon))
    if option == 1 and empty == 3:
        print(int(math.sqrt(a * a + b * b) + sys.float_info.epsilon))
    if option == 2 and empty == 1:
        print(c // 2 + b)
    if option == 2 and empty == 2:
        print(a - c // 2)
    if option == 2 and empty == 3:
        print((a - b) * 2)
    if option == 3 and empty == 1:
        print(c // b)
    if option == 3 and empty == 2:
        print(c // a)
    if option == 3 and empty == 3:
        print(a * b)

if __name__ == "__main__":
    main()