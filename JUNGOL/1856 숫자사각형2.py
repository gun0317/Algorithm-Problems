nm = input()
n = int(nm.split()[0])
m = int(nm.split()[1])

toPrint = 1
even = 0

for r in range(n):
    if even%2 == 0:
        for c in range(m):            
            print(toPrint, end=' ')
            toPrint += 1
    else:
        toPrint += m - 1
        for c in range(m):
            print(toPrint, end=' ')
            toPrint -= 1
        toPrint += m + 1
    even += 1
    print()
