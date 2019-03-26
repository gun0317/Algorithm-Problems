n = int(input())
small = int()
big = int()

idx = 0

for i in range(1,n):
    idx += 1
    if (idx * idx > n):
        break
    if (n%i == 0):
        small = i
        big = n/i
        
print(int(big-small))
