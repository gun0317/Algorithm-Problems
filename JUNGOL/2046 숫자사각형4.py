nm = input()
n = int(nm.split()[0])
m = int(nm.split()[1])

toPrint = 1

if m == 1:
    for r in range(n):
        for c in range(n):
            print(toPrint, end=' ')
        print()
        toPrint += 1


if m == 2:
    even = 0
    for r in range(n):
        if even%2 == 0:
            for c in range(n):
                print(toPrint, end=' ')
                toPrint += 1
            toPrint = 1
            even += 1
            
        elif even%2 == 1:
            toPrint = n
            for c in range(n):
                print(toPrint, end=' ')
                toPrint -= 1
            toPrint = 1
            even += 1
        print()


if m == 3:
    toAdd = 1
    for r in range(1,n+1):
        for c in range(n):
            print(r, end=' ')
            r += toAdd
        print()
        toAdd += 1

        
