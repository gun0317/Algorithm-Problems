T = int(input())

for t in range(T):
    destRow, destCol, targetCost = list(map(int, input().split()))
    cost = 0
    if 1*(destCol - 1) + destCol*(destRow-1) == targetCost:
        print("yes")
    else:
      print("no")
