import math

T = int(input())

for t in range(T):
  line = list(map(int, input().split()))
  more = max(line[0], line[1])
  less = min(line[0], line[1])
  print(math.ceil(more/less) - 1)
  if line[2] >= math.ceil(more/less) - 1:
    print("YES")
  else:
    print("NO")
  