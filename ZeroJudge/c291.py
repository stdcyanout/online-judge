n = int(input())
fd = list(map(int,input().split()))
check = [0] * n
gp = 0
c = 0

while c<n:
  if check[c] == 0:
    if c == fd[c]:
      gp += 1
      check[c] = 1
      c += 1
      pass
    else:
      check[fd[c]] = 1
      fd[c] = fd[fd[c]]
      pass
  else:
    c += 1
    pass
print(gp)